/*****************************************************************************
* Model: icbm.qm
* File:  ./bsp.h
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/*${.::bsp.h} ..............................................................*/
#ifndef bsp_h
#define bsp_h

#include <xc.h>

#define FOSC_HZ                 32000000.0    /* clock */
                                       /* instruction cycle clock frequency */
#define FCY_HZ                  (FOSC_HZ / 2.0)

#define FCY FCY_HZ

                                               /* the system tick rate [Hz] */
#define BSP_TICKS_PER_SEC    100UL

                                /* controlling the LED */
//LED on RB15
#define LED_ON()                LATBbits.LATB15 = 0
#define LED_OFF()               LATBbits.LATB15 = 1

/* A4960 constants */
#define A4960_CONF0_RD 0
#define A4960_CONF0_WR 1
#define A4960_CONF1_RD 2
#define A4960_CONF1_WR 3
#define A4960_CONF2_RD 4
#define A4960_CONF2_WR 5
#define A4960_CONF3_RD 6
#define A4960_CONF3_WR 7
#define A4960_CONF4_RD 8
#define A4960_CONF4_WR 9
#define A4960_CONF5_RD 0x0a
#define A4960_CONF5_WR 0x0b
#define A4960_MASK_RD 0x0c
#define A4960_MASK_WR 0x0d
#define A4960_RUN_RD 0x0e
#define A4960_RUN_WR 0x0f

#ifdef UNDEF

typedef struct __attribute__((__packed__)) tagConfig0 {
    union {
        uint16_t val;
        struct {
            unsigned dt:6;
            unsigned bt:4;
            unsigned cb:2;
            unsigned reg:4;
        };
    };
} A4960_CONFIG0;

typedef struct __attribute__((__packed__)) tagConfig1 {
    union {
        uint16_t val;
        struct {
            unsigned vt:6;
            unsigned vr:4;
            unsigned :2;
            unsigned reg:4;
        };
    };
} A4960_CONFIG1;

typedef struct __attribute__((__packed__)) tagConfig2 {
    union {
        uint16_t val;
        struct {
            unsigned pt:5;
            unsigned :7;
            unsigned reg:4;
        };
    };
} A4960_CONFIG2;

typedef struct __attribute__((__packed__)) tagConfig3 {
    union {
        uint16_t val;
        struct {
            unsigned ht:4;
            unsigned hq:4;
            unsigned ids:1;
            unsigned :3;
            unsigned reg:4;
        };
    };
} A4960_CONFIG3;

typedef struct __attribute__((__packed__)) tagConfig4 {
    union {
        uint16_t val;
        struct {
            unsigned sc:4;
            unsigned ec:4;
            unsigned :4;
            unsigned reg:4;
        };
    };
} A4960_CONFIG4;

typedef struct __attribute__((__packed__)) tagConfig5 {
    union {
        uint16_t val;
        struct {
            unsigned rr:4;
            unsigned rq:4;
            unsigned pa:4;
            unsigned reg:4;
        };
    };
} A4960_CONFIG5;

typedef struct __attribute__((__packed__)) tagMask {
    union {
        uint16_t val;
        struct {
            unsigned cl:1;
            unsigned ch:1;
            unsigned bl:1;
            unsigned bh:1;
            unsigned al:1;
            unsigned ah:1;
            unsigned vc:1;
            unsigned vb:1;
            unsigned va:1;
            unsigned los:1;
            unsigned ts:1;
            unsigned tw:1;
            unsigned reg:4;
        };
    };
} A4960_MASK;

typedef struct __attribute__((__packed__)) tagRun {
    union {
        uint16_t val;
        struct {
            unsigned run:1;
            unsigned dir:1;
            unsigned brk:1;
            unsigned rsc:1;
            unsigned dg:2;
            unsigned esf:1;
            unsigned bw:3;
            unsigned bh:2;
            unsigned reg:4;
        };
    };
} A4960_RUN;

#define A4960_DIAGNOSTIC A4960_MASK

#endif    //UNDEF


/* Menu item definition */
typedef struct item_t {                //item structure
    const char* const name;
    const char* const unit;
    uint8_t point;
    uint8_t reg;
    uint16_t mask;
    uint16_t(*get)(struct item_t*);
    uint16_t(*set)(uint16_t, struct item_t*);
    uint16_t(*conv)(struct item_t*);
} ITEM;

/* Config field definition format */
typedef struct field_t {
    const char* const title;            //what is printed on the screen
    const char* const unit;             //unit of measurement
    uint8_t point;                      //decimal point
    uint8_t reg;                        //register
    uint16_t mask;                      //field mask
    uint16_t(*conv)(struct field_t*);    //conversion utility
} FIELD;

/*${BSP::BSP_init} .........................................................*/
void BSP_init(void);

/*${BSP::A4960::Common::A4960_xfer} ........................................*/
uint16_t A4960_xfer(uint8_t reg, uint16_t data);

/*${BSP::A4960::Common::getField} ..........................................*/
uint16_t getField(FIELD* field);

/*${BSP::A4960::Common::setField} ..........................................*/
uint16_t setField(uint16_t val, FIELD* field);


/*${BSP::PWM::PWM_getPeriod} ...............................................*/
uint16_t PWM_getPeriod(void);

/*${BSP::PWM::PWM_setPeriod} ...............................................*/
uint16_t PWM_setPeriod(uint16_t val, ITEM* item);

/*${BSP::PWM::PWM_getDuty} .................................................*/
uint16_t PWM_getDuty(void);

/*${BSP::PWM::PWM_setDuty} .................................................*/
void PWM_setDuty(uint16_t val);



#endif                                                             /* bsp_h */
