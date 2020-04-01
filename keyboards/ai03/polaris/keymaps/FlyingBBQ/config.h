#pragma once

#define MANUFACTURER    FlyingBBQ

#ifdef RGB_DI_PIN
  #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
  #undef RGBLIGHT_ANIMATIONS /* disable all animations */
  #define RGBLIGHT_EFFECT_BREATHING /* enable only breathing */
#endif

/* Leader key settings */
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250
