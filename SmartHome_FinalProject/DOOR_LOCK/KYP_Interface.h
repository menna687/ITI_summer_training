#ifndef KYP_INTERFACE_H
#define KYP_INTERFACE_H

                      /* MACROS */
#define ALL_NOT_PRESSED  (0xFF)    //number out of possible output range
#define SWITCH_PRESSED        (0x00)
#define SWITCH_NOT_PRESSED    (0x01)

              /* Functions Prototypes*/
void KYP_voidInit(void);
u8 KYP_u8GetPressedKey(void);

#endif
