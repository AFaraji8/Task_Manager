# Task_Manager
The purpose of writing this program is to divide and manage the work of an organization among the employees of this organization.
• Attributes:
• The program is always ready to take orders from the user.
Today command: Displays today's tasks.
• month command: Displays the tasks of this month.
• task add command: takes the new task from the input user (task name, start and end date in mm format: dd-mm hh:mm)[day-month hour:minute (Enter all as numbers)] and saves in the file.
• time find command: This command with the input hh:mm should find an empty interval with this period in the current month, priority with
The nearest empty time is possible. If there is no blank interval, suggest an interval with the least overlap.
• Now command: The program prints the date and time.
• free command: This command with input dd-mm hh:mm deletes all tasks of this date.
• Employee add command: Takes an employee's profile (name, national code, daily working hours) and adds it to the list of employees.
Task assignment: Takes an employee's national code and job name and assigns the job to that employee.
• Schedule command: This command with date entries in dd-mm format and the national code of an employee, first the previous work of the employee in it
Clears the day and then has to assign and print the largest subset of work to be done that day.
• Save the changes in the file with the exit command and exit.
