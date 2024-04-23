# Wheelie
This is a summary of a project to make a two-wheeled scooter that can be used while sat upon, rather than stood upon.

It is based on a two-wheeled scooter, known as an Ecorider and the device needs to be stabilised when first sat upon (it is a chair) and then with the flick of a switch it goes into balance mode and becomes a scooter.

To make it into a chair the design uses two linear actuators that drive down and form legs for the device, making a stable mechanical configuration with the driving wheels. On their first touch on the ground the balance mode must be inhibited else the scooter would be offset.  This would have adverse consequences because the offset is the arrangement that is normally automatically corrected and is the basis for actuating the forward/backward drive of the scooter.  The approach used is to have the legs fitted in a sliding socket (about 5mm in vertical deflction) and limit switches that inform the software that each leg has landed.  On finding BOTH legs landed the PLC immediately switches off the balance mode and the device becomes a passive 'chair'.

Balance mode is normally actuated by one of four foot-pressure buttons being pressed down on the footplate and a spade interrupts the flow of light across a yoke-shaped photoswitch.  The reciever side of the photoswitch goes open-circuit once the light is interrupted and this signal sets the device into balance-mode.  It is possible to simulate this effect with a simple on-off switch -- and this becomes the user control for switching from scooter to chair
