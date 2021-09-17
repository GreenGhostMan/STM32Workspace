; Import systeminit; Delete systeminit write RCC initialization function by yourself
; LDR r0, = systeminit
; Blx R0
The following is a setup function that uses HSI as the system clock. If the PLL is not practical, the HSI is directly output to the MCO pin:
Void my_rccinitmcohsi (void)
{
Uint8_t temp;
My_rcc_deinit ();
RCC-> Cr | = 1 <0; // reset hsion to enable the internal clock. In fact, the internal clock is not needed, and the internal clock is automatically used at startup.
While (! (RCC-> Cr> 1); // check whether HSI is ready
RCC-> cfgr & = (~ 0x03); // clears the 0-bit and 1-bit Hsi of cfgr as the system clock.
While (temp! = 0x00) // read the cfgr 2 and 3 to determine whether the HSI is set as the system clock.
{
Temp = RCC-> cfgr> 2;
Temp & = 0x03;
}
// At this time, HSI has become the system clock
// Output directly to MCO (pa8) after the HSI clock is ready)
RCC-> apb2enr | = 1 <2; // enable PA clock
RCC-> apb2enr | = 1 <5; // enable the portd clock
Gpioa-> CRH & = 0xfffffff0;
Gpioa-> CRH | = 0x0000000b; // pa8 push-pull output (MCO)
//// Set the internal HSI clock output by MCO
RCC-> cfgr | = 5 <24; // MCO output HSI clock
// RCC-> cfgr | = 4 <24; MCO output system clock sysclk
// In this case, you can see the output waveform on the pa8 or MCO pin. The two are the same.
}
Below is the diagram from the oscilloscope:

HSE is directly used as sysclk. Similar to HSI
The setting method is as follows, with comments in the Code:
Void my_rccinitmcohse (void)
{
Uint8_t temp;
My_rcc_deinit ();
RCC-> Cr | = 1 <16; // enable hseon to enable the external clock.
While (! (RCC-> Cr> 17); // wait for the HSE to be ready

// Select HSE as the system clock


While (temp! = 0x01) // read the cfgr 2 and 3 to determine whether HSE is set as the system clock.
{
Temp = RCC-> cfgr> 2;
Temp & = 0x03;
}
// At this time, HSE has become the system clock
// After the HSE clock is ready, it is directly output to MCO (pa8)
RCC-> apb2enr | = 1 <2; // enable PA clock
Gpioa-> CRH & = 0xfffffff0;
Gpioa-> CRH | = 0x0000000b; // pa8 push-pull output (MCO)

// Set the internal HSE clock output by MCO
RCC-> cfgr | = 0x06 <24; // MCO output HSE clock
// RCC-> cfgr | = 4 <24; MCO output system clock sysclk
// In this case, you can see the output waveform on the pa8 or MCO pin. The two are the same.
}

The PLL part only contains the code and diagram. It was just written for half a day and prompts that only five messages can be submitted in 2 minutes, and then it will be gone.
Depressed, don't want to write any more
Void my_rccinitmcopll (uint8_t PLL)
{
Uint8_t temp;
My_rcc_deinit ();
RCC-> Cr | = 1 <16; // enable hseon to enable the external clock.
While (! (RCC-> Cr> 17); // wait for the HSE to be ready
// Select HSE as the system clock
// RCC-> cfgr | = 0x01;
// Set the number of PLL Multiplier
PLL-= 2; // Based on the PLL multiplier coefficient and the 18 to 21 bits of RCC-> cfgr (pllmul)
RCC-> cfgr | = PLL <18;
RCC-> cfgr | = 1 <16; // HSE is used as the PLL clock source.
RCC-> Cr | = 1 <24;
While (! (RCC-> Cr> 25); // wait for the PLL to lock
// Select the PLL output as the system clock source
RCC-> cfgr | = 0x02;
While (temp! = 0x02) // read the cfgr 2 and 3 to determine whether HSE is set as the system clock.
{
Temp = RCC-> cfgr> 2;
Temp & = 0x03;
}
// At this time, HSE has become the system clock
// After the HSE clock is ready, it is directly output to MCO (pa8)
RCC-> apb2enr | = 1 <2; // enable PA clock
Gpioa-> CRH & = 0xfffffff0;
Gpioa-> CRH | = 0x0000000b; // pa8 push-pull output (MCO)
// Set the internal HSE clock output by MCO
RCC-> cfgr | = 0x07 <24; // MCO output HSE clock
// RCC-> cfgr | = 4 <24; // MCO output system clock sysclk
// In this case, you can see the output waveform on the pa8 or MCO pin. The two are the same.
}