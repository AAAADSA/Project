## Ticket Booking Module

## Overview

This module is responsible for managing train ticket bookings, including recording booking details, processing payments, and updating ticket statuses. It is part of a larger train ticketing system and provides functionality for booking, searching, modifying, and displaying booking records.

### Functions Overview

1. **`printGreen(const char* text)`**: Displays text in green color.
2. **`printRed(const char* text)`**: Displays text in red color.
3. **`printCyan(const char* text)`**: Displays text in cyan color.
4. **`printBlue(const char* text)`**: Displays text in blue color.
5. **`validateIC(const char* ic)`**: Checks if the IC number is 12 digits long.
6. **`validatePhoneNumber(const char* phoneNumber)`**: Validates if the phone number is 9 or 10 digits long and starts with '01'.
7. **`isSeatAvailable(const char(*seatNumbers)[5], int quantity, const char* newSeat)`**: Checks seat availability.
8. **`bookingregister()`**: Allows user registration.
9. **`bookinglogin()`**: Allows user login.
10. **`bookingrecovery(const char* memberID)`**: Enables password recovery.
11. **`bookingMain()`**: Displays the main menu (register, login, exit).
12. **`printCoach(int seats)`**: Displays seat layouts and class types.
13. **`validateAccountNumber(const char* accountNumber)`**: Checks if the account number is 10 digits long.
14. **`selectSeat(struct Booking* bookings, const char* trainID)`**: Allows seat selection and booking details entry.
15. **`payment(struct Booking* bookings, double price01, double price02, int quantity)`**: Displays booking details and processes payment.
16. **`payPending(const char* memberID)`**: Checks and processes pending payments.
17. **`addBooking(const char* memberID)`**: Allows users to add a booking.
18. **`displayBooking(const char* memberID)`**: Displays all booking details for the user.
19. **`modifyBooking(const char* memberID)`**: Allows modification of existing bookings.
20. **`cancelBooking(const char* memberID)`**: Allows cancellation of bookings.
21. **`searchBooking(const char* memberID)`**: Searches for bookings by ID or train ID.
22. **`bookingMenu(const char* memberID)`**: Main menu for booking actions.
23. **`validateDate(const char* date)`**: Validates date format and correctness.

## Data Fields

- **Booking ID**: Unique identifier for the booking (e.g., B1001)
- **Member ID**: Identifier for the member making the booking (e.g., M1001)
- **Train ID**: Identifier for the train (e.g., T1001)
- **Booking Date**: Date when the booking was made (e.g., 21/01/2024)
- **Departure Date**: Date of train departure (e.g., 12/02/2024)
- **Seat Number**: Assigned seat number (e.g., 14A)
- **Coach**: Coach where the seat is located (e.g., B)
- **Quantity**: Number of tickets booked (e.g., 1)
- **Payment Info**: Payment method used (e.g., Credit Card)
- **Amount**: Total amount for the booking (e.g., 65.00)
- **Ticket Status**: Current status of the ticket (e.g., Booked)

## File Handling

- **File Format**: Uses binary files to store booking records.
- **File Operations**: Implemented functions to read, write, update, and delete records.

### User Interface and Outputs
- **Main Menu**: Users can choose to register, log in, or exit.
- **Registration**: Prompts user for valid member ID and password; errors in format prompt for re-entry.
- **Password Recovery**: Users can recover their password by answering a security question. Success or failure messages are displayed accordingly.
- **Login**: Users enter member ID and password. Incorrect details prompt for re-entry or password recovery.
- **Booking Actions**: Users can add, search, modify, display, pay for, or cancel bookings. Each action involves validations and prompts based on user input.
- **Seat Selection**: Depending on train availability and coach type, users select seats with specific constraints.
- **Payment**: Users confirm payment details, including bank account information. Invalid inputs prompt for re-entry.

  ## Setup
1. Download the zip file.
2. Run it using [Visual Studio](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false#installvs)

## Sample Output
![Screenshot 2024-09-26 205842](https://github.com/user-attachments/assets/7ffd2ed5-cc8d-4d4a-87b8-d30249201f86)
![Screenshot 2024-09-26 205827](https://github.com/user-attachments/assets/1c3ca76f-e2a8-4747-a18d-70eb66eeb134)
![Screenshot 2024-09-26 205813](https://github.com/user-attachments/assets/46daa73d-3de9-4c95-9ed7-bd4b19c7d0e2)
![Screenshot 2024-09-26 205757](https://github.com/user-attachments/assets/202fd0b4-e13c-43e3-a01e-e7ef286d24ec)
![Screenshot 2024-09-26 205747](https://github.com/user-attachments/assets/c43de155-a80e-43c6-9578-876673abdac9)
![Screenshot 2024-09-26 205636](https://github.com/user-attachments/assets/1cde0e0c-71a2-425f-bd80-2a32593cf4fc)
![Screenshot 2024-09-26 205631](https://github.com/user-attachments/assets/0c87b791-6bda-49c5-b87e-ccbe3b79b7eb)
![Screenshot 2024-09-26 205619](https://github.com/user-attachments/assets/a186c27e-ed0a-42a0-ade6-0250926f2ce4)
![Screenshot 2024-09-26 205455](https://github.com/user-attachments/assets/f155df91-eca1-46f4-af16-483a6bc54f40)



