#include <stdio.h>
#include "hal_data.h"

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER



////////////////////////////
/// Reserving MD pins and jtag interfaces is strongly recommended in hardware design.
/// Because you can use the swd interface in Single-Chip mode;
/// In addition, you can lower the MD pin to enter the SCI Boot mode during power-on.
/// In this way, you can modify some necessary Settings using the sci interface
///
/**
 * if enable SEGGER_RTT_V780c/Syscalls, pls #define PRINTF 0,
 * then redirect printf to SEGGER_RTT.
 */
#pragma message("if enable files:SEGGER_RTT_V780c/Syscalls,pls #define PRINTF 0,then redirect printf to SEGGER_RTT.")
#define PRINTF 1

#ifndef PRINTF
#define PRINTF 1
#endif

#if PRINTF
/**
 * notice: g_uart9CB; g_uart9_ctrl
 *
 * e2s:
 * 1.uart9 callback:g_uart9CB
 * 2.FSP-BSP-heap size:0x1000
 * 3.-u _printf_float
 * 4.other link void
 *
 * iar:
 * 1.uart9 callback:g_uart9CB
 * 2.FSP-BSP-heap size:0x1000
 * 3.libray=full
 * 4.Semihosted=None
 *
 * keil:
 * 1.uart9 callback:g_uart9CB
 * 2.FSP-BSP-heap size:0x1000
 */
volatile bool uart_send_complete_flag = false;
void g_uart9CB (uart_callback_args_t * p_args)
{
    switch (p_args->event)
    {
        case UART_EVENT_RX_CHAR:
        {
            break;
        }
        case UART_EVENT_TX_COMPLETE:
        {
            uart_send_complete_flag = true;
            break;
        }
        default:
            break;
    }

}
#if defined __GNUC__ && !defined __clang__
int _write(int fd, char *pBuffer, int size); //??????
int _write(int fd, char *pBuffer, int size)
{
   (void)fd;
   fsp_err_t err = R_SCI_UART_Write(&g_uart9_ctrl, (uint8_t *)pBuffer, (uint32_t)size);
   if(FSP_SUCCESS != err) __BKPT();

   while(uart_send_complete_flag == false);
   uart_send_complete_flag = false;

   return size;
}
#else
int fputc(int ch, FILE *f)
{
   (void)f;
   fsp_err_t err = R_SCI_UART_Write(&g_uart9_ctrl, (uint8_t *)&ch, 1);
   if(FSP_SUCCESS != err) __asm("bkpt 0");
   while(uart_send_complete_flag == false);
   uart_send_complete_flag = false;

   return ch;
}
#endif//#if defined __GNUC__ && !defined __clang__
#endif//PRINTF



/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void)
{
    /* TODO: add your own code here */
    fsp_err_t err = FSP_SUCCESS;
    err = g_uart9.p_api->open(&g_uart9_ctrl, &g_uart9_cfg);
    if(err == FSP_SUCCESS)
    {
        const char *log_uart_init = "\napp log uart init successed!!!\r\n";
        g_uart9.p_api->write(&g_uart9_ctrl, (uint8_t*)log_uart_init, strlen(log_uart_init));
        while(uart_send_complete_flag == false)
        {;}
        uart_send_complete_flag = false;
    }
    printf("\nprintf redirect successed!!!\ndate:%s\ntime:%s\nfile:%s\nfunc:%s,line:%d\nhello world!\n", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__);

    const char dlmlist[] = "0x1: CM 0x2: SSD 0x3: NSECSD 0x4: DPL 0x5: LCK_DBG 0x6: LCK_BOOT 0x7: RMA_REQ 0x8: RMA_ACK ";
    printf("%s\n", dlmlist);

    uint8_t dlm = R_PSCU->DLMMON_b.DLMMON;
    char dlm_str[20] = {0};
    sprintf(dlm_str, "dlm mode:%d\n", dlm);
    printf("%s", dlm_str);

    uint8_t cfs2 = R_PSCU->CFSAMONA_b.CFS2;
    sprintf(dlm_str, "cfs2:%d\n", cfs2);
    printf("%s", dlm_str);

    uint8_t cfs1 = R_PSCU->CFSAMONB_b.CFS1;
    sprintf(dlm_str, "cfs1:%d\n", cfs1);
    printf("%s", dlm_str);

    uint8_t dfs = R_PSCU->DFSAMON_b.DFS;
    sprintf(dlm_str, "dfs:%d\n", dfs);
    printf("%s", dlm_str);

    uint8_t ss2 = R_PSCU->SSAMONA_b.SS2;
    sprintf(dlm_str, "ss2:%d\n", ss2);
    printf("%s", dlm_str);

    uint8_t ss1 = R_PSCU->SSAMONB_b.SS1;
    sprintf(dlm_str, "ss1:%d\n", ss1);
    printf("%s", dlm_str);



#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
#if BSP_FEATURE_FLASH_LP_VERSION != 0

        /* Enable reading from data flash. */
        R_FACI_LP->DFLCTL = 1U;

        /* Would normally have to wait tDSTOP(6us) for data flash recovery. Placing the enable here, before clock and
         * C runtime initialization, should negate the need for a delay since the initialization will typically take more than 6us. */
#endif
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open (&g_ioport_ctrl, &IOPORT_CFG_NAME);
    }
}

#if BSP_TZ_SECURE_BUILD

FSP_CPP_HEADER
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ();

/* Trustzone Secure Projects require at least one nonsecure callable function in order to build (Remove this if it is not required to build). */
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ()
{

}
FSP_CPP_FOOTER

#endif