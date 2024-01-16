/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = iic_master_rxi_isr, /* IIC1 RXI (Receive data full) */
            [1] = iic_master_txi_isr, /* IIC1 TXI (Transmit data empty) */
            [2] = iic_master_tei_isr, /* IIC1 TEI (Transmit end) */
            [3] = iic_master_eri_isr, /* IIC1 ERI (Transfer error) */
            [4] = r_icu_isr, /* ICU IRQ0 (External pin interrupt 0) */
            [5] = spi_rxi_isr, /* SPI0 RXI (Receive buffer full) */
            [6] = spi_txi_isr, /* SPI0 TXI (Transmit buffer empty) */
            [7] = spi_tei_isr, /* SPI0 TEI (Transmission complete event) */
            [8] = spi_eri_isr, /* SPI0 ERI (Error) */
            [9] = sci_uart_rxi_isr, /* SCI9 RXI (Received data full) */
            [10] = sci_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [11] = sci_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [12] = sci_uart_eri_isr, /* SCI9 ERI (Receive error) */
            [13] = ether_eint_isr, /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [14] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [15] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [16] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [17] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [18] = sci_uart_rxi_isr, /* SCI1 RXI (Received data full) */
            [19] = sci_uart_txi_isr, /* SCI1 TXI (Transmit data empty) */
            [20] = sci_uart_tei_isr, /* SCI1 TEI (Transmit end) */
            [21] = sci_uart_eri_isr, /* SCI1 ERI (Receive error) */
            [22] = sci_uart_rxi_isr, /* SCI2 RXI (Received data full) */
            [23] = sci_uart_txi_isr, /* SCI2 TXI (Transmit data empty) */
            [24] = sci_uart_tei_isr, /* SCI2 TEI (Transmit end) */
            [25] = sci_uart_eri_isr, /* SCI2 ERI (Receive error) */
            [26] = sci_uart_rxi_isr, /* SCI3 RXI (Received data full) */
            [27] = sci_uart_txi_isr, /* SCI3 TXI (Transmit data empty) */
            [28] = sci_uart_tei_isr, /* SCI3 TEI (Transmit end) */
            [29] = sci_uart_eri_isr, /* SCI3 ERI (Receive error) */
            [30] = sci_uart_rxi_isr, /* SCI4 RXI (Received data full) */
            [31] = sci_uart_txi_isr, /* SCI4 TXI (Transmit data empty) */
            [32] = sci_uart_tei_isr, /* SCI4 TEI (Transmit end) */
            [33] = sci_uart_eri_isr, /* SCI4 ERI (Receive error) */
            [34] = sci_uart_rxi_isr, /* SCI5 RXI (Received data full) */
            [35] = sci_uart_txi_isr, /* SCI5 TXI (Transmit data empty) */
            [36] = sci_uart_tei_isr, /* SCI5 TEI (Transmit end) */
            [37] = sci_uart_eri_isr, /* SCI5 ERI (Receive error) */
            [38] = sci_uart_rxi_isr, /* SCI6 RXI (Received data full) */
            [39] = sci_uart_txi_isr, /* SCI6 TXI (Transmit data empty) */
            [40] = sci_uart_tei_isr, /* SCI6 TEI (Transmit end) */
            [41] = sci_uart_eri_isr, /* SCI6 ERI (Receive error) */
            [42] = sci_uart_rxi_isr, /* SCI7 RXI (Received data full) */
            [43] = sci_uart_txi_isr, /* SCI7 TXI (Transmit data empty) */
            [44] = sci_uart_tei_isr, /* SCI7 TEI (Transmit end) */
            [45] = sci_uart_eri_isr, /* SCI7 ERI (Receive error) */
            [46] = sci_uart_rxi_isr, /* SCI8 RXI (Received data full) */
            [47] = sci_uart_txi_isr, /* SCI8 TXI (Transmit data empty) */
            [48] = sci_uart_tei_isr, /* SCI8 TEI (Transmit end) */
            [49] = sci_uart_eri_isr, /* SCI8 ERI (Receive error) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_IIC1_RXI), /* IIC1 RXI (Receive data full) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_IIC1_TXI), /* IIC1 TXI (Transmit data empty) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_IIC1_TEI), /* IIC1 TEI (Transmit end) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_IIC1_ERI), /* IIC1 ERI (Transfer error) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ0), /* ICU IRQ0 (External pin interrupt 0) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SPI0_RXI), /* SPI0 RXI (Receive buffer full) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TXI), /* SPI0 TXI (Transmit buffer empty) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TEI), /* SPI0 TEI (Transmission complete event) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_SPI0_ERI), /* SPI0 ERI (Error) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_SCI9_RXI), /* SCI9 RXI (Received data full) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TXI), /* SCI9 TXI (Transmit data empty) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TEI), /* SCI9 TEI (Transmit end) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_SCI9_ERI), /* SCI9 ERI (Receive error) */
            [13] = BSP_PRV_IELS_ENUM(EVENT_EDMAC0_EINT), /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [14] = BSP_PRV_IELS_ENUM(EVENT_SCI0_RXI), /* SCI0 RXI (Receive data full) */
            [15] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TXI), /* SCI0 TXI (Transmit data empty) */
            [16] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TEI), /* SCI0 TEI (Transmit end) */
            [17] = BSP_PRV_IELS_ENUM(EVENT_SCI0_ERI), /* SCI0 ERI (Receive error) */
            [18] = BSP_PRV_IELS_ENUM(EVENT_SCI1_RXI), /* SCI1 RXI (Received data full) */
            [19] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TXI), /* SCI1 TXI (Transmit data empty) */
            [20] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TEI), /* SCI1 TEI (Transmit end) */
            [21] = BSP_PRV_IELS_ENUM(EVENT_SCI1_ERI), /* SCI1 ERI (Receive error) */
            [22] = BSP_PRV_IELS_ENUM(EVENT_SCI2_RXI), /* SCI2 RXI (Received data full) */
            [23] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TXI), /* SCI2 TXI (Transmit data empty) */
            [24] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TEI), /* SCI2 TEI (Transmit end) */
            [25] = BSP_PRV_IELS_ENUM(EVENT_SCI2_ERI), /* SCI2 ERI (Receive error) */
            [26] = BSP_PRV_IELS_ENUM(EVENT_SCI3_RXI), /* SCI3 RXI (Received data full) */
            [27] = BSP_PRV_IELS_ENUM(EVENT_SCI3_TXI), /* SCI3 TXI (Transmit data empty) */
            [28] = BSP_PRV_IELS_ENUM(EVENT_SCI3_TEI), /* SCI3 TEI (Transmit end) */
            [29] = BSP_PRV_IELS_ENUM(EVENT_SCI3_ERI), /* SCI3 ERI (Receive error) */
            [30] = BSP_PRV_IELS_ENUM(EVENT_SCI4_RXI), /* SCI4 RXI (Received data full) */
            [31] = BSP_PRV_IELS_ENUM(EVENT_SCI4_TXI), /* SCI4 TXI (Transmit data empty) */
            [32] = BSP_PRV_IELS_ENUM(EVENT_SCI4_TEI), /* SCI4 TEI (Transmit end) */
            [33] = BSP_PRV_IELS_ENUM(EVENT_SCI4_ERI), /* SCI4 ERI (Receive error) */
            [34] = BSP_PRV_IELS_ENUM(EVENT_SCI5_RXI), /* SCI5 RXI (Received data full) */
            [35] = BSP_PRV_IELS_ENUM(EVENT_SCI5_TXI), /* SCI5 TXI (Transmit data empty) */
            [36] = BSP_PRV_IELS_ENUM(EVENT_SCI5_TEI), /* SCI5 TEI (Transmit end) */
            [37] = BSP_PRV_IELS_ENUM(EVENT_SCI5_ERI), /* SCI5 ERI (Receive error) */
            [38] = BSP_PRV_IELS_ENUM(EVENT_SCI6_RXI), /* SCI6 RXI (Received data full) */
            [39] = BSP_PRV_IELS_ENUM(EVENT_SCI6_TXI), /* SCI6 TXI (Transmit data empty) */
            [40] = BSP_PRV_IELS_ENUM(EVENT_SCI6_TEI), /* SCI6 TEI (Transmit end) */
            [41] = BSP_PRV_IELS_ENUM(EVENT_SCI6_ERI), /* SCI6 ERI (Receive error) */
            [42] = BSP_PRV_IELS_ENUM(EVENT_SCI7_RXI), /* SCI7 RXI (Received data full) */
            [43] = BSP_PRV_IELS_ENUM(EVENT_SCI7_TXI), /* SCI7 TXI (Transmit data empty) */
            [44] = BSP_PRV_IELS_ENUM(EVENT_SCI7_TEI), /* SCI7 TEI (Transmit end) */
            [45] = BSP_PRV_IELS_ENUM(EVENT_SCI7_ERI), /* SCI7 ERI (Receive error) */
            [46] = BSP_PRV_IELS_ENUM(EVENT_SCI8_RXI), /* SCI8 RXI (Received data full) */
            [47] = BSP_PRV_IELS_ENUM(EVENT_SCI8_TXI), /* SCI8 TXI (Transmit data empty) */
            [48] = BSP_PRV_IELS_ENUM(EVENT_SCI8_TEI), /* SCI8 TEI (Transmit end) */
            [49] = BSP_PRV_IELS_ENUM(EVENT_SCI8_ERI), /* SCI8 ERI (Receive error) */
        };
        #endif
