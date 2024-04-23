# Wheelie
This is a summary of a project to make a two-wheeled scooter that can be used while sat upon, rather than stood upon.

It is based on a two-wheeled scooter, known as an Ecorider and the device needs to be stabilised when first sat upon (it is a chair) and then with the flick of a switch it goes into balance mode and becomes a scooter; it thereby becomes stable by being self-balancing.

To make it into a chair the design uses two 12V linear actuators that drive down and form legs for the device, making a stable mechanical configuration (four-point contact) with the driving wheels. On their first touch on the ground the the drive must be stopped and balance mode inhibited else the scooter would be offset.  This would have adverse consequences because the offset is the arrangement that is normally automatically corrected and is the basis for actuating the forward/backward drive of the scooter.  The approach used is to have the legs fitted in a sliding socket (with about 5mm in vertical deflction) and limit switches that inform the software when each leg has landed.  On finding each leg landed the PLC stops the downward drive of that leg and when BOTH legs are landed the PLC immediately switches off the balance mode and the device becomes a passive 'chair'.  There is a flow chart that shows the details of this protocol.

Balance mode is normally actuated by (a minimum of) one of four foot-pressure buttons being pressed down on the footplate. This results in a spade interrupting the flow of light across a yoke-shaped photoswitch.  The receiver side of the photoswitch goes open-circuit once the light is interrupted and this signal sets the device into balance-mode.  It is possible to simulate this effect with a simple on-off switch -- and this is provided by the PLC becomes the user control for switching from scooter to chair.

The user control switch for scooter/chair is read by the PLC and it switches the linear actuator drives and the balance-mode on/off according to the protocol described above.

The 12V linear actuators are driven by EM-324C DC Motor Controllers supplied by Electromen Oy.  They provide the forward/reverse power switching (for leg up and down) based on a 12V signal from the PLC to the FW/BW pins on the board.  The factory setting for 'start' with a ramp-up in speed is tolerable, but the motor needs to be abruptly stopped when the limit switches are actuated to avoid the device being offset and the wheels beginning to move unexpectedly.  Setting thabrupt stop parameter requires use of the plug-in Electromen Oy EM-236 interface unit

