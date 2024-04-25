# Wheelie
This is a summary of a project to make a two-wheeled scooter that can be used while sat upon, rather than stood upon.

It is based on a two-wheeled scooter, known as an Ecorider and the device needs to be stabilised when first sat upon (as if it were a chair) and then with the flick of a switch it goes into balance mode and becomes a scooter; it thereby becomes stable by being self-balancing.

To make it into a chair the design uses two 12V linear actuators that drive feet down and form legs for the device, making a stable mechanical configuration (four-point contact including the driving wheels). On their first touch on the ground the linear actuator drives must be stopped and balance mode inhibited else the scooter would be offset.  This would have adverse consequences because the offset is the arrangement that is normally automatically corrected and is the basis for implementing the forward/backward drive of the scooter.  The design approach used here is to have the legs fitted in a sliding socket (with about 5mm in vertical deflection) and limit switches that are actuated by the deflection. They inform the software when each foot/leg has landed.  On finding each leg landed the PLC abruptly stops the downward drive of that leg and when BOTH legs are landed the PLC immediately switches off the balance mode so that the device becomes a passive 'chair'.  There is a flow chart that shows the details of this protocol.

Balance mode is normally actuated by (a minimum of) one of four foot-pressure buttons being pressed down on the footplate. This results in a spade interrupting the flow of light across a yoke-shaped photoswitch.  The receiver side of the photoswitch goes open-circuit once the light is interrupted and this signal sets the device into balance mode.  It is possible to simulate this effect with a simple on-off switch -- and this is provided by the PLC for switching from scooter to chair.

The manual user control switch (on/off) for scooter/chair is read by the PLC and it switches the linear actuator drives and the balance mode on/off according to the protocol described above.

The 12V linear actuators are driven by EM-324C DC Motor Controllers supplied by Electromen Oy.  They provide the forward/reverse power switching (for leg up and leg down) based on a 5V signal from the PLC to the FW/BW pins on the controller board.  The factory setting on the controllers for 'start' with a gradual ramp-up in speed is tolerable, but the linear actuator motor needs to be abruptly stopped when the limit switches are actuated -- to avoid the scooter being tipped and the drive wheels beginning to move unexpectedly.  Setting/programming the abrupt stop parameter requires use of the plug-in Electromen Oy EM-236 interface unit: a programming accessory for the boards.

For safety there should be a sequence that regularly checks the battery voltage, and when it falls to a point suggesting limited power remaining a warning LED should be lit.  If the voltage drops further to a point where the residual power is small then the software should drive the scooter into chair mode.  This will make it stable should the power drop completely and the balance mode capability is lost.  If this (loss of balance mode capability) were to happen the scooter would simply fall over much to the discomfort of a seated passenger.

The steering capability is driven in the Ecorider using a Hall Effect probe on the main Ecorider tiller.  For the purposes of the two-wheeled sit-on scooter the probe may be taken to the arm of the scooter chair and fitted into a freely-moving automatically-centring lever (a left-right joystick) and the wire to the socket on the circuit board may be simply extended to connect the two.  The steering drive is only active when the scooter is in balance mode

The software quoted is that which was programmed for use in a 19R Boot and Work (Barcelona) Mduino PLC for protyping purposes.  This PLC is an industrially adapted Arduino platform.  This PLC was used for prototyping convenience and a bare Arduino board could have served the same purpose

**** WARNING ****

None of the content of this page is validated, nor necessarily safe to replicate.  The author takes no responsibility for third parties using the data and methods here.  The project was only produced for interest/amusement of the author
