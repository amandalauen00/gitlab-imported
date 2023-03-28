#include "gpio.h"

void accelGPIO ( int &gpio_info, int adjust_num )
{
        unsigned int shiftResult;
        unsigned int mask = 3932160;
        int mask_num = gpio_info & mask;
        shiftResult = mask_num >> 18;
        int new_num = shiftResult + adjust_num;
        if(new_num > 15)
        {
            new_num = 15;
        }
        if (new_num < 0)
        {
            new_num = 0;
        }
        
        shiftResult = new_num << 18;
        unsigned int mask_2 = -3932161;
        int mask_2_num = gpio_info & mask_2;  
        gpio_info = mask_2_num | shiftResult;
    
}