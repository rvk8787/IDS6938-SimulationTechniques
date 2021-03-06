# Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)


## Part 1: Empirical Tests of Randomness (20 pts).

* **(a) - 3pts:** Output the results of five different random number engines, using a uniform distribution for values between [0-100]. Generate useful charts and statistics from the output to analyze how uniform these values truly are. You are expected to look at some advanced statistics and test, for example: tests like the Kolmogorov-Smirnov test, Chi-square test, Autocorrelation test, and Spearman’s Rank Correlation Coefficient are a few examples of ones your could use.)
 


* **(b) - 2pts:**  Vary *N* (amount of samples). How do things change.


* **(c) - 3pts:** Fix a random engine of your choice from part (a), and now vary five different [distributions](http://www.cplusplus.com/reference/random/) for just the psedo-random numbers. Again, analyze your results with graphs and statistics of choice.

* **(d)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different random number engines. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines.

| ![](images/unitsquare_plots.png?raw=true)  |

* **(e)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different distributions. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines. (See [Random Numbers Webcourse page](https://webcourses.ucf.edu/courses/1246518/pages/random-numbers?module_item_id=10541423) for a rough idea what you should produce.)

| ![](images/unitsquare_plots1.png?raw=true)  |

* **(f)- 4pts:** Repeat parts (d) and (e) with a unit circle.

## Part 2 - Snakes and Ladders (Discrete Event Markov Chains and Monte Carlo Simulations) (30 pts)



* **(a) Null State Game transition matrix - 10pts:** The *null state game* is defined by a game with no snakes and no ladders. This simplifies the game to just the moves of the two dice rolls. Create the transition matrix for the null state game. The Transition Matrix would be decided by the roll of a fair, six-sided die, so it would start to look like:


A null transition matrix was created in the "transitionmatrix.h" using the for loop which generated a transition matrix as per requirements. with each row having 6 states with equal probability of (1/6) corresponding to the players' current position. 


* **(b) Simulate and analyze the results of Null State Game - 10pts:** What is the modal number of moves required by a single player to finish the game? We will be simulating the game two different ways. **(1) Markov Chain**: The game can be analyzed with a row vector, *v* with 101 components, representing the probabilities that the player is on each of the positions. V(0) is (1,0,0,...,0) since we know we start at square 0. v evolves by: <BR>![](images/prob.png?raw=true)<BR>

For this part (1) use the *Markov project* in the Snake and Ladders starter code.<BR>
**(2) Monte Carlo**: he will will use a monte carlo process to solve our Discrete Time Markov Chains. Here (2) use the DTMC project, and utilize the DTMC method similar to what we did in class. <BR><BR>Produce graphs to analyze the results and show how the game evolves over time for both methods. Plot useful statistics of the results such as percentage chance of finishing the game in n-moves, cumulative probability of finishing the game in n-moves, and other ways to convey useful information of the results.

* **(c) Simulate and analyze the results of Snakes and Ladders -10pts:**  Construct a new transition matrix based on the table:


Ladders From  | Ladders To | |  Snakes From  | Snakes To 
-------- | -------- | ------------- | -------- | -------- 
3|19| |11|7
15|37| |18|13
22|42| |28|12
25|64| |36|34
41|73| |77|16
53|74| |47|26
63|86| |83|39
76|91| |92|75
84|98| |99|70



Run the same simulation and analyze your results similar to part (b) for the proper game of *Snakes and Ladders* for both methods. How often are the snakes and ladders used, how do the probability of finishing change, etc? What is the maximum and expected amount of moves for the game? Use charts and graphs to illustrate these points.
* **(d) Think - 0pts:** If these games are built entirely on chance, do they require any strategy? Is it really a *game*, would you rather play games of chance or games of strategy?


## Part 3 - Discrete Event Simulation - Queue Simulation (30 pts)

This problem will look at queues and commonly used performance measures. For this problem we will look to design a simple airport security check. We will make the following assumptions: (1) there is only one airline - Southwest; (2) passengers' interarrival times are independent and identically distributed (IID) with an exponential distribution with mean 1 / lambda. The service times are also assumed to be IID and exponentially distributed random variables with mean 1 / mu.
<BR>![](images/queue.png?raw=true)<BR>
When a passanger arrives they have to wait in a queue to present their ID and ticket to the gate agent with all the other passengers. Once approved by the agent they will have to pass through a security check. Since this is Orlando, there are only 3 open metal/screening devices open and again passangers have to wait in a queue. After passing through security you again have to wait in a queue to board your plane.

* **(a) - 4pts:** To start create the senario in the figure above in *main.cpp*. Checkin will have a *mu* of 53 and accept new arrivals, the security gates will have a *mu* of 20, and will not accept new arrivials, boarding will have a *mu* of 80. You will have to set up  the appropriate *MM1_Queue* objects to capture the functionality above.

		Queue objects were created for Checkin (with mu=53), Security 1(with mu=20), security 2 (with mu=20), & Security 3 (with mu=20) and Boarding (with mu=80)
	

* **(b) - 4pts:** You want to add a check that your process is within an error range *is_within_error_range(float)* where the error range will be 0.002. You also want to process the next event, and add an external arrival where marked.
		Added checks in the for loop to check for the error range for the checkin, security 1, security 2 & security 3using the following code snippet
		
		!Checkin.is_within_error_range(0.002)||
	   !Security1.is_within_error_range(0.002)||
	   !Security2.is_within_error_range(0.002)||
	   !Security3.is_within_error_range(0.002)

* **(c) - 3pts:** in *mm1_queue.cpp* : add code to caculate the expected results for: 

The expected results were calculated asfollows:  
 *  expected_server_utilization = lambda/mu
  *    expected idle prob= 1- expected Server utilization
  *   expected queue length = ((expected server utilization)^2)/(1-expected_server_utilization))
  *  expected number customers = expected server utilization/(1-expected_server_utilization)
  * expected waiting time = expected server utilization / (mu-lambda)
  * expected response time = 1/(mu-lambda)
*  **(d) - 4pts:** Write code to call the functions to output and generate data from the airport senario. Plot and analyze the useful statistics/results in the program of your choice.  (Hint -  basically call  *.output();* on the MM1_Queue objects you create. Hint2 - two other use functions are *get_current_time()* and  *plot_results_output()* call intially on your intial MM1_Queue object.)  

The output data was generated by calling the plot_results function for the airport scenario:

The following functions were used to collect data:
		* Checkin.plot_results_output() for checkin results
		* Security1.plot_results_output() for security 1 results
		* Security2.plot_results_output() for security 2 results
		* Security3.plot_results_output() for security 3 results
		* Boarding.plot_results_output() for Boarding results
		
		The plots for the different scenarios are as follows: 
		
| ![](images/Queue_Results.png?raw=true)  |

* **(e) - 15pts:** Download the personal edition of **[Anylogic](http://www.anylogic.com/)**, read through the [documentation](http://www.anylogic.com/learn-simulation) as needed, and set up the same type of simulation discussed above.

An anylogic model for the airport scenario was created and successfully run using the same parameters for the queueing simulation.
The Anylogic files are included in the Homework 2 Folder under "Anylogic_Airport_Queue"
| ![](images/anylogic.PNG?raw=true)  |

## Part 4 - Implementing Extra Features (10 pts)
Implementing 2 features on the extra features list. Pick any feature on the "*extra features*" list below to customize your assignment to fit your interests. Please document this in your writeup. (*Note: These should total 10pts. You could successfully implement a feature worth 10pts or greater. This also fulfills this requirement. The features are assigned points based on difficulty. The 5pt features are more straightforward.*)
* **(10 Points)** - Add a 2D visualization to AnyLogic for Part 3.
The Anylogic files are included in the Homework 2 Folder under "Anylogic_Airport_Queue"

A 2d Visualization of the airport scenario was created based on the anylogic queuing model in part 3 and successfully run.

| ![](images/Anylogic_2D.PNG?raw=true)  |

* **(10 Points)** - Add a 3D visualization to AnyLogic for Part 3.

A 3d Visualization of the airport scenario was created based on the anylogic queuing model in part 3 and successfully run.
The Anylogic files are included in the Homework 2 Folder under "Anylogic_Airport_Queue"

| ![](images/Full.PNG?raw=true)  |




