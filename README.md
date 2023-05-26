<h1>Philosopher</h1>
<h2>Introduction</h2>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/simon-zerisenay/42_Philosophers?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/simon-zerisenay/42_Philosophers?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/simon-zerisenay/42_Philosophers?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/simon-zerisenay/42_Philosophers?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/simon-zerisenay/42_Philosophers?color=green" />
</p>
Welcome to the Philosopher project! This project is part of the curriculum at 42 and focuses on solving the dining philosophers problem using threads and synchronization techniques. The dining philosophers problem is a classic synchronization problem in computer science that illustrates resource sharing and deadlock avoidance.

<h2>Objective</h2>
The main objective of the Philosopher project is to design a program that simulates the dining philosophers problem, where a certain number of philosophers sit around a table with a shared set of forks. The philosophers alternate between thinking and eating, but to eat, they must pick up the two adjacent forks. The challenge is to ensure that each philosopher can successfully eat without causing a deadlock or starvation.

<h2>Features</h2>
<h3>Program Design</h3>
The Philosopher project involves designing a program that simulates the dining philosophers problem. The key features of the program include:

<h3>Philosophers:</h3> 
The program represents philosophers as individual threads, each responsible for alternating between thinking and eating.
<h3>Forks:</h3> 
The forks are shared resources used by the philosophers to eat. Each philosopher needs two adjacent forks to eat.
<h3>Synchronization:</h3> 
The program must implement synchronization mechanisms to ensure that the philosophers can access the forks without causing conflicts or deadlocks. Techniques such as mutexes, semaphores, or other synchronization primitives can be used.
<h2> Dining Philosophers Problem</h2>
The dining philosophers problem presents several challenges that need to be addressed in the program design:

<h3>Deadlock Avoidance:</h3>
The program must implement a strategy to avoid deadlock, where each philosopher is waiting for a fork held by the philosopher next to them.
<h3>Resource Sharing:</h3>
The forks are shared resources that need to be properly managed to prevent conflicts and ensure fairness.
<h3>Starvation Prevention:</h3>
The program should prevent starvation, ensuring that each philosopher gets a fair chance to eat.
<h2>Installation and Usage</h2>
To install and run the Philosopher project, follow these steps:

Clone the project repository: 

				git clone https://github.com/your_username/42-philosopher.git
Navigate to the project directory: 
				
					cd 42-philosopher
Compile the project using the provided Makefile: 

				   		 make
Run the program with the desired number of philosophers: 

	./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
Ensure that you have the necessary libraries and dependencies installed on your system. The project's repository may provide further instructions on any additional requirements.

<h2>Testing</h2>
To test the Philosopher project and evaluate its functionality, follow these steps:

Run the program with different configurations, including various numbers of philosophers and different time constraints.
Observe the behavior of the philosophers and verify that they alternate between thinking and eating.
Monitor the synchronization mechanisms to ensure that the philosophers share the forks properly and avoid deadlock.
Test the program with edge cases, such as a single philosopher or a large number of philosophers, to validate its robustness and performance.
Measure the program's resource utilization and efficiency to ensure optimal performance.
By conducting thorough testing, you can ensure the correctness and effectiveness of your implementation of the dining philosophers problem.
<br/>
<br/>
Note: The optional argument [number_of_times_each_philosopher_must_eat] allows you to specify a condition where each philosopher must eat a certain number of times before the program terminates.
