# Bulk Club Class Project

## Rules

* Be respectful to one another.

* Each person is required to complete their share of work

* If they are not able to they must let the other team members known in the groupchat

## Coding standards

Follow [this](https://llvm.org/docs/CodingStandards.html) with some exceptions when necessary. Although, you must follow the following requirements:
 * If a class is intended to be used as a QT window, it must be postfixed with `Window`. For exmaple, instead of declaring the login class `Login`, you must declare it `LoginWindow`

## Spec
Your team is to write a program that supports the Bulk Club.   At least one class must contain a pointer (a copy constructor needs to be written and tested).   Highlight the above.  Your team is to write at least 10 agile stories (including description, tasks, test scenarios, and story points) before software is developed).  Your team must use an agile management tool (e.g. Waffle.io), Graphical User Interface (GUI) such as QT, DOXYGEN, and GIT.    Only team members should have access to their repository.

The team must follow the Scrum process (the Scrum master must log all team meetings and the product owner must document the backlog).

Sprint schedule:

Schedule:

* **First checkpoint – April 13th**

* **Second checkpoint – April 27th**

* **Final checkpoint – May 11th**

Bulk Club has two types of members: Regular and Executive
Member information includes:
* Member name
* Membership number
* Membership type
* Membership expiration date
* Total amount spent (running total)
* Rebate amount (Executive members only)

A rebate of 2% of the total amount spent (not to include sales tax) is paid at the close of the year to the Executive members. Regular members pay annual dues of $65.00 and Executive members pay annual dues of $120.00. Your program will use the following files that will be provided:

* A membership information file (warehouse shoppers) is provided with the following format:
  * Customer name
  * Customer membership number
  * Type of customer – Regular or Executive
  * Membership expiration date

* Seven sales files are provided with the following format:
  * Purchase date
  * Customer membership number
  * Item purchased
  * Sales price quantity purchased

Your program should read from the daily sales file and update the members&#39; information accordingly. As the sales are processed the total amount spent and rebate data for each member should be updated. Use a sales tax rate of 7 3/4% for all revenue totals.

Generate the following displays at any time:

1. A store manager should be able to display a sales report for any given day. It should include a list of items and quantities sold on that day as well names of the members who shopped that day.  Display the total revenue for the given day.  It should also include number of Executive members and Regular members who shopped during the given day.  Your team should provide an option to generate the display by membership type.
2. A store manager should be able to display the total purchases for each member sorted by membership number.  The display should also include a grand total of all the purchases for all the members.
3. A store manager should be able to display the quantity of each item sold sorted by item name and the total revenue for each item.
4. A store manager should be able to display the rebate of all the Executive members sorted by membership number.
5. A store manager should be able to enter a month and obtain a display of all members whose memberships expire that month as well as the cost to renew their memberships.
6. An administrator should be able to add/delete Bulk Club members.
7. Your team should provide the capability to create purchases for the new members to validate your software.
8. An administrator should be able to add (with a corresponding price), delete items, and change prices from the inventory list.
9. A store manager should be able to enter an item name and display the quantity of that item sold as well as the total revenue for the item.
10. A store manager should be able to enter a membership number __or__ name and display the total purchases for that member.
11. Your program should be able to determine if any Regular customer should convert their membership to Executive status. Display the number of recommended conversions.
12. An administrator should be able to determine if any Executive customer should convert their membership to Regular status. Display the number of recommended conversions.
13. Your software should require the store manager and administrator to logon to obtain access to your program.
14. Your software should be able to save all changes between executions.

Please let me know your partners by March 25th (two points will be deducted from your score if you do not meet this deadline). All projects are due by May 11th.   **No late projects will be accepted.**  Your team must demonstrate your project before it will be graded.   Each teammate must identify their accomplishments on the project. Not all team members will necessarily earn the same score.  The UML diagrams should be shown during the Sprint 1 checkpoint.

* Design a very readable, easy to use interface to demonstrate your program.
* Contingency handling should include addressing invalid input.
* Write at least 10 agile stories (including description, tasks, test scenarios, and story points) before any software is developed.  The team must follow the Scrum process (the Scrum master **must** document all meetings and the product owner must document the backlog).
* Submit a test plan.
* Submit a UML class diagram, at least three use cases, and at least three state diagrams, and one activity diagram with your project.
* All changes must be persistent between executions.
* Submit your software, coding standards and team rules.
* Each team must use a version control system, graphical user interface tool, automated documentation tool, and an Agile management tool. (GITHUB, DOXYGEN, WAFFIO.IO, QT, etc.)
* Each individual must critique their team members via e-mail.
* The planning poker cards must be returned.
* All artifacts are due on May 11th.



The assignment will be graded using the following scale:
|                                       | Value |
|---------------------------------------|-------|
| Checkpoint 1                          | 6     |
| Checkpoint 2                          | 6     |
| Meet requirements                     | 66    |
| Coding Style/Style Guide              | 1     |
| User interface                        | 2     |
| Test plan                             | 4     |
| Adherence to Scrum/Team Rules         | 4     |
| UML                                   | 4     |
| DOXYGEN                               | 1     |
| Big O (1 point for each method)       | 5     |
| Contingency handling                  | 1     |
| Total                                 | 100   |
| Continuous Integration (extra credit) | 2     |
| Total with extra credit               | 102   |


MIT License

Copyright © 2020

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
