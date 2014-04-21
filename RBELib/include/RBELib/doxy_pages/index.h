/**
 * @file index.h
 *
 *
 * @author Kevin Harrington
 * @date February 21, 2010
 * @brief This is the index file for Doxygen..
 *
 * @author Eric Willcox
 * @date August 20, 2013
 */
 
 /**
 * @mainpage 3001 RBELib
 * @section welcome Welcome to RBE 3001
 * <br />
 * Here you will find all the documentation that you need for working with RBELib which will contain
 * function prototypes for everything that you will need throughout the course.  While it is possible to complete
 * the course without using RBELib, using it will make your code easier to maintain as you get closer to the final
 * project as well as follow proper coding practice as outlined in the syllabus.
 * 
 * As you progress through the course, it is encouraged that you keep your own version of RBELib with your SVN repository
 * so that you can add to things such as the To Do list and function descriptions as you go.
 * <br /><br /> <br />
 * @section rbelib RBELib Files
 * <br />
 * @link ADC.h ADC @endlink <strong> Pages 233 - 252 </strong>
 *
 * Here you will find everything relating to the Analog to Digital Converter (ADC) that you should need.  You will have to make your own
 * corresponding functions for these prototypes.
 * <hr>
  * <table>
 * <tr> <th colspan="2"> Pages 65 - 85  </th> </tr>
 * <tr> <td>
 * @link PORTAdriver.h Port A @endlink 
 * </td> <td>
 * @link PORTBdriver.h Port B @endlink 
 *</td> </tr>
 * <tr> <td>
 * @link PORTCdriver.h Port C @endlink
 * </td> <td>
 *  @link PORTDdriver.h Port D @endlink
 * </td> </tr>
 * </table>
 *Port A/B/C/D contains the code for manipulating the ports on the chip that you can access via the breakout board.  Keep in mind
 * that some of these are also connected to components on the board such as the SPI line, if you have a problem using a pin and
 * on-board components, <b> CHECK THE DATASHEET AND BOARD LAYOUT  </b> to make sure that you are not using the same
 * pin for your buttons that you are for the MOSI while using SPI or etc..
 *<hr>
 * @link Debug.h Printing @endlink
 *
 * This contains all the printing statements that you should need for debugging your code.  Whenever you have a problem and can't find
 * out what it is, first try to print out all of your code and add long delays so that you can see what is happening.
 *
 * You do NOT need to make any functions for printing, it is all done for you!
 *<hr>
 * @link Periph.h Peripherals @endlink <strong> See respective datasheets for each peripheral.</strong>
 *
 * Here is where all code for peripheral devices such as the IR sensor and accelerometer go.  You will have to make your own
 * functions for these prototypes.
 *<hr>
 * @link PID.h PID @endlink
 *
 * This is where all PID code goes for the calculation.  You will need to create your own calculation using the formulas that you used in class
 * and optimize them for running on and embedded system.
 *<hr>
 * @link RBELib.h RBELib Macros @endlink
 *
 * Here are all of the includes for RBELib as well as some of the macros that you may find useful to use (such as INPUT/OUTPUT instead of 0/1).
 * You do not need to create anything additional.
 *<hr>
 * @link reg_structs.h Reg Structs @endlink
 *
 * Reg Strucs contain a lot of useful shorthand notations that you can use for specifying bits when manipulating registers.  Each register
 * has the datasheet page you can look at to find out more information of what each of the settings do.  
 * You do not need to create anything additional.
 *<hr>
 * @link SetServo.h Servo (Conveyer/Gripper) @endlink
 *
 * This is used for moving the conveyer belt and opening/closing the gripper.  You do not need to create anything additional.
 *<hr>
 * @link SPI.h SPI @endlink <strong> Pages 154 - 163 </strong>
 *
 * For initializing the SPI and and sending data through it.  You need to create the functions for the prototypes.
 *<hr>
 * @link timer.h Timers @endlink <strong> Pages 86 - 153 (Timers 0-2) </strong>
 *
 * Allows you to initialize any one of the timers and set their comparative values for when they reset.  You need to create the functions for the
 * prototypes.
 *<hr>
 * @link USARTDebug.h USART @endlink <strong> Pages 164 - 190 (In SPI mode, pages 191 - 199) </strong>
 *
 * This should be the very first thing that you work on.  This allows you to use serial printing within your code through the use of the USART.
 * You do need to create your functions for the prototypes.
 *<hr>
 * @link pot.h Potentiometers @endlink
 *
 * These functions can be used to get the potentiometer values in degrees, voltage, or ADC counts.  You need to make your own functions for
 * the prototypes.
 * <br />
 * @section helpful Other Helpful Links
 * <br />
 * @link bug Bug List @endlink
 *
 * This is a place where any bugs in RBELib and your code should be documented.
 *<hr>
 * @link todo To Do @endlink
 *
 * Things that still need to be done in the RBELib and or your code.
 * <hr>
 * @link datatypes Data Types @endlink
 *
 * This lets you know the number of bytes in any given data type.
 */
