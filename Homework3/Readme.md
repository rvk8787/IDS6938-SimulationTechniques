# Homework 3 : Agent based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #3. 

The assignment is due: **Monday, April  24 at 11:59PM (EST)**

# Introduction
The goal of this assignment is to enable the behavioral animation of vehicle-like walking agents. 

You will be expected to compose a *final report* which demonstrates your understanding on the material in each section of the assignment. Be visual! - Pictures say a thousand words so you do not have to. Show off your different configurations and really explore the assignment.


### Part 1: Behaviors

The goal of this assignment is to enable the steering behavioral animation of agents.

We represent an agent as a two-dimensional disk with mass (**m**) and moment-of-inertia (**I**) that is capable of generating a force **F** along body x-axis with a torque about the z-axis. For this assignment assume that the agent only translates in the world x-y plane and rotates about the body z-axis.

![](images/behavior.png?raw=true)

**(a) - 10 points** : Compute derivative vector given input and state vectors. Implement the function *SIMAgent::FindDeriv()*. This function sets derive vector to appropriate values after being called.

Description of agent state vector and input vector:  
* state[0] is the position of the agent in local body coordinates (almost useless in this project);  
* state[1] is the orientation angle of the agent with respect to world (i.e. global) coordinates;  
* state[2] is the velocity of the agent  in local body coordinates.  
* state[3] is the angular velocity of the agent in world coordinates. 
* input[0] is the force in local body coordinates;  
* input[1] is the torque in local body coordinates

You will need to set deriv[0], deriv[1], deriv[2], deriv[3]. Compute derivative vector given input and state vectors. This function sets derive vector to appropriate values after being called. 
* deriv[2] is the velocity of the agent  in local body coordinates
 
    deriv[2]= force in local body coordinates/ Mass


* deriv[3] is the angular velocity of the agent in world coordinates

    deriv[3]= torque in local body coordinates/Inertia


* deriv[0] is the force in local body coordinates divided by the mass.

    deriv[0]= position of the agent in local body coordinates

* deriv[1] is the torque in local body coordinates divided by the inertia.

    deriv[1]= angular velocity of the agent in world coordinates

You also must implement *SIMAgent::InitValues()*: Try to figure out appropriate values for control and behavior settings. You need to find out appropriate values for: *SIMAgent::Kv0, SIMAgent::Kp1, SIMAgent::Kv1, SIMAgent::KArrival, SIMAgent::KDeparture,
SIMAgent::KNoise,	SIMAgent::KWander, SIMAgent::KAvoid, SIMAgent::TAvoid, SIMAgent::RNeighborhood, SIMAgent::KSeparate, SIMAgent::KAlign, SIMAgent::KCohesion.*

Set the Initial Values for control and behavior settings

  Kv0 = 10.0;
	Kp1 = 10.0;
	Kv1 = 10.0;
	KArrival = 1.0;
	KDeparture = 2.0;
	KNoise = 10.0;
	KWander = 10.0;
	KAvoid = 10.0;
	TAvoid = 10.0;
	RNeighborhood = 10.0;
	KSeparate = 10.0;
	KAlign = 10.0;
	KCohesion = 10.0;

**(b) - 20 points**: In this part of the assignment you will need to implement 6 types of individual behaviors and 5 types of group behaviors. Create the following behaviors through appropriate computation of V<sub> d</sub>  and θ<sub>d</sub>  commands:

** Seek
 
 Agents in the Simultion seek a user defined (picked) point on the 2D plane.
 
 Computed desired velocity and desired orientation from the Global coordinates of the agent and the goal position.
 
 Executed seek() function in the Agent.cpp 
 
 
** Flee

 Agents in the Simultion flee from a user defined (picked) point on the 2D plane.
 
 Computed desired velocity and desired orientation from the Global coordinates of the agent and the goal position.

 Used MaxVelocity parameter to dictate veocity.

 Executed Flee() function in the Agent.cpp 
 
** Arrival

 Agents in the Simultion arrive at a user defined (picked) point on the 2D plane.
 
 Computed desired velocity and desired orientation from the Global coordinates of the agent and the goal position.
 
 Used KArrival parameter to dictate veocity.
 
 Executed Arrive() function in the Agent.cpp 

** Departure
  
 Agents in the Simultion depart from a user defined (picked) point on the 2D plane.
 
 Computed desired velocity and desired orientation from the Global coordinates of the agent and the goal position.
 
 Used KDeparture parameter to dictate veocity.
 
 Executed Departure() function in the Agent.cpp 


** Wander
    
 Agents in the Simultion wander on the 2D plane.
 
 Computed desired velocity and desired orientation from the Global coordinates of the agent and the goal position and random number    generator.
 
 Used KWander parameter and KNoise to make agents wander around on the 2D plane.
 
 Executed Wander() function in the Agent.cpp 


** Obstacle Avoidance

 Agents in the Simultion avoid randomly placed objects on the 2D plane.
 
 Computed desired velocity and desired orientation from the Global coordinates of the agent and the goal position.
 
 Used Kavoid & Tavoid parameters to avoid obstacles. 
 
 Executed Wander() function in the Agent.cpp 

**(c) - 20 points**: Implement the functions for the following group behaviors: 
* Seperation
* Cohesion 
* Alignment 
* Flocking
* Leader Following

# Part 2 - Simulating a simple pedestrian flow

The goal of this part of the assigment is to simulate the pedestrain flow for various configurations. Pedestrian traffic simulation is an important, sometimes required, stage for certain construction projects such as shopping centers, airports, railway stations, or stadiums. hese analyses can be used by architects in the design stage, by facilities owners contemplating changes, by city planners to evaluate rush hours, or even by civil authorities to simulate evacuations or other emergencies. 

![](images/flow.png?raw=true)

**(a) - 0 points**: Follow the Anylogic example for the [Subway Entrance example](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/tutorial/Subway_Entrance.html). Create the appropriate [boundaries and walls](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/markup/Wall.html), and the display ther pedestrian density map, [statistics](https://help.anylogic.com/index.jsp?nav=/4_1_5), [2D and 3D animations](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Animation.html).

![](images/density.png?raw=true)

**(b) - 20 points**: Create a maze. Generate the pdm, stats, and animations like before. Vary [parameters in your agents](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Attributes.html) to give them different behaviors and show the pedistrians change how they navigate the maze.

** Created a simple maze from an image file.
  * Constructed walls by tracing wall feature along the maze 
  * Created a pedestrian source and sink
  * Created pedestrian target lines for enabling pedestrians to follow a path to the end of the maze
  * Images below show maze in 2D, maze in 3D, pedestrian density map, and entry and exit traffic and intensity statistics
  * Also attached is a video of the anylogic simulation.
  
  ![](images/maze.jpg?raw=true)
  
  ![](images/Maze_Sim.PNG?raw=true)
 	
	** Link to maze Simulation: 
	
	https://youtu.be/1hE_FtMlJVc
  
 Anylogic source code, model and simulation included in the "anylogic" folder.

**(c) - 30 points**: Model and analyze a building (or floor/outdoor space/stadium) on campus. (There is help on piazza how to find rough building plans - we expect something plausible). Create a senario: evacuation, daily office routine, special event, normal egress.... etc., and model and design your own experiment to determine if the building design suits the needs of its users. Start with photographs of your site, describe your site, describe your senario and hypothesis. Then use an agent-based pedistrian simulation to visualize your experiment's results.

** Created the Library Level 5 model from an image of floor plan obtained from UCF Library.
 
 ![](images/Library.PNG?raw=true)
 
  * Constructed walls by tracing wall feature along Library 
  
   
 ![](images/Sketch.PNG?raw=true)
  
  * Created a pedestrian source at 4 points and exit at 4 points
 
 In the figure below: 
 * inflow500 is the ped source at "500" stairway with an arrival rate of 100.
 
 * inflow501: is the ped source at "580" stairway with an arrival rate of 50.
 
 * inflow502: is the ped source at Elevator 1  with an arrival rate of 100.
 
 * inflow503: is the ped source at Elevator 3  with an arrival rate of 50.
 
![](images/ped_Flow.PNG?raw=true)
![](images/ped_Flow_2.PNG?raw=true)
    * Entrances: Elevator 1, 3, "500" Stairway, & "580" Stairway
    * Exits : Elevator 2, 4, 5, "570" Stairway. 
    * Pedestrians take different pathe from entry to exit.
    * pedestrians wait in archives, cataloguing area and conference room.
    * pedestrians wait for service in the Library admin with 3 service lines to get service.
    
  * Created pedestrian target lines for enabling pedestrian statistics
  
  * Placed 6 cameras at different locations near the entrances and exits of the library to monitor pedestrian behavior
  
   
![](images/cameras.PNG?raw=true)
 
  
  * Images below show Library Level 5 in 2D and in 3D, pedestrian density map, and entry and exit traffic and intensity statistics
  * Also attached is a video of the anylogic simulation.

 
![](images/Library_Day.PNG?raw=true)
 
 * Pedestrian Statistics showing pedestrian traffic and intensity across the entrances and exits
 * Pedestrian traffic at 5 different locations in the library: 1. Hallway, 2. Archive, 3. Conference Room, 4. Library Admin, 5. Cataloguing
 
![](images/Ped_stats.PNG?raw=true)
 
 This information might be particularly useful to train library staff for expected busy/ quiet hours and further simulate different conditions for estimating pedestrian traffic during peak hours.
 
 
 
 
** Link to Library Simulation: 

https://youtu.be/ePatpT_Heng


Anylogic source code, model and simulation included in the "anylogic" folder.
