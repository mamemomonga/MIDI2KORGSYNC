# Serial Port シリアルポート
AR_PORT=/dev/cu.usbserial-2001

# Sketch スケッチ
# AR_SKETCH=$(notdir $(basename $(shell find . -name '*.ino')))
AR_SKETCH=app

# -----------------
#   MegaTinyCore (ATtiny1604, 20MHz, UPDI)
#   https://github.com/SpenceKonde/megaTinyCore/blob/master/megaavr/extras/ATtiny_x04.md
AR_FQBN=megaTinyCore:megaavr:atxy4:chip=1604,millis=enabled
AR_PROGRAMMER=-P jtag2updi
# -----------------
