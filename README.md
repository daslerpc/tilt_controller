# tilt_controller
An Arduino sketch for a tilt based controller for the 2048 game.

The controller uses two orthogonally placed tilt switches to sense tilting in four directions.  The sketch is state based and transitions between states when a tilt switch has read a steady value for some number of cycles (this number is determined by the TARGET_COUNT constant).  This provides simple software debounce.

When the state changes to a direction, the subsequent arrow key is "pressed" using the Arduino keyboard library.