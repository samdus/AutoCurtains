#ifndef IR_REMOTE_HPP
#define IR_REMOTE_HPP

#include <model/i_model.hpp>
#include <IRremote.h>
#include <pins_mapping.hpp>

#if !defined(REMOTE_RECV_PIN)
#   error Must define RECV pin for the IR Remote controller
#endif

#define IR_BTN_POWER 0xFFA25D
#define IR_BTN_MODE 0xFF629D
#define IR_BTN_SOUND 0xFFE21D
#define IR_BTN_PREV 0xFF22DD
#define IR_BTN_NEXT 0xFF02FD
#define IR_BTN_PLAY 0xFFC23D
#define IR_BTN_VOL_DOWN 0xFFE01F
#define IR_BTN_VOL_UP 0xFFA857
#define IR_BTN_EQ 0xFF906F
#define IR_BTN_0 0xFF6897
#define IR_BTN_100_PLUS 0xFFA857
#define IR_BTN_BACK 0xFFB04F
#define IR_BTN_1 0xFF30CF
#define IR_BTN_2 0xFF18E7
#define IR_BTN_3 0xFF7A85
#define IR_BTN_4 0xFF10EF
#define IR_BTN_5 0xFF38C7
#define IR_BTN_6 0xFF5AA5
#define IR_BTN_7 0xFF42BD
#define IR_BTN_8 0xFF4AB5
#define IR_BTN_9 0xFF52AD

class IrRemote : public IModel, public IRrecv {
    public:
        decode_results lastResult;

        IrRemote() : IRrecv(REMOTE_RECV_PIN) {}

        void init();
        int decode();
};

#endif