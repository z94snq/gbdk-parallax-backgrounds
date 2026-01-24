#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdint.h>
#include "graphics/FlappyBirdBackground.h"

uint16_t scrollValue = 0;

void HandleBackgroundScrolling(){
    switch(LYC_REG){
        case 0:
            // the interrupt should next trigger here
            LYC_REG = 65;

            // no movement
            SCX_REG = 0;

            break;
        
        case 65:
            // the interrupt should next trigger here
            LYC_REG = 79;

            // move everything below on the background (until next interrupt)
            SCX_REG = scrollValue >> 7;

            break;

        case 79:
            // the interrupt should next trigger here
            LYC_REG = 95;

            // move everything below on the background (until next interrupt)
            SCX_REG = scrollValue >> 5;

            break;

        case 95:
            // the interrupt should next trigger here
            LYC_REG = 116;

            // move everything below on the background (until next interrupt)
            SCX_REG = scrollValue >> 3;

            break;

        case 116:
            // the interrupt should next trigger here
            LYC_REG = 0;

            // move everything below on the background (until next interrupt)
            SCX_REG = scrollValue;

            break;
    }
}

void main(void){
    // set background tiles in vram
    set_bkg_data(0, FlappyBirdBackground_TILE_COUNT, FlappyBirdBackground_tiles);

    // set background tiles colors in vram
    set_bkg_palette(0, FlappyBirdBackground_PALETTE_COUNT, FlappyBirdBackground_palettes);

    SHOW_BKG;
    DISPLAY_ON;
    
    // set background tiles attributes
    VBK_REG = 1;
    set_bkg_tiles(0, 0, FlappyBirdBackground_WIDTH >> 3, FlappyBirdBackground_HEIGHT >> 3, FlappyBirdBackground_map_attributes);

    // set background tiles
    VBK_REG = 0;
    set_bkg_tiles(0, 0, FlappyBirdBackground_WIDTH >> 3, FlappyBirdBackground_HEIGHT >> 3, FlappyBirdBackground_map);

    // use interrupts to achieve parallax scrolling
    // set the LYC register at 0, where we will start the scrolling logic
    // from there we will move diferent chunks of the background different amounts
    STAT_REG |= STATF_LYC; // prepare LYC=LY interrupt when LCD/STAT interrupts are enabled
    LYC_REG = 0u; // set the scanline where interrupt first triggered
    CRITICAL{
        add_LCD(HandleBackgroundScrolling);
    }
    set_interrupts(LCD_IFLAG|VBL_IFLAG); // additionally enable LCD interrupr

    // loop forever
    while(1){
        scrollValue += 10;

        // wait for next frame
        wait_vbl_done();
    }
}