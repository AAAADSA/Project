#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h >
#pragma warning(disable:4996)
typedef struct {
    char id[20];
    char departureStation[100];
    char arriveStation[100];
    char departureTime[20];
    char arrivalTime[20];
    char date[20];
    int availableSeats;
    double economyPrice;
    double firstClassPrice;
} Train;

typedef struct {
    char userID[50];
    int password;
    int phoneNumber;
} User;
typedef struct {
    char birth[30];
    char birthplace[30];
    int birthnum;
}IC;

typedef struct {
    char memberID[15];
    char name[30];
    char password[30];
    char password_recovery[30];
    char gender;
    IC memberIC;
    char phonenum[30];
}Member;

typedef struct {
    char staffID[7];
    char staffName[20];
    char password[20];
    char passwordRecovery[20];
    char email[20];
    char position[4];
    char ic[15];
    char religion[10];
    char phoneNumber[12];
    char age[3];
    char action[10];
    char staffAffectedName[20];
    char staffAffectedID[7];
}staff;

void red();
void green();
void black();
void staffManage();
void staffRegister();
void staffLogin();
void staffActionMenu(staff loggedInStaff);
void addStaffData(staff loggedInStaff);
void searchStaffData();
void modifyStaffData(staff loggedInStaff);
void displayStaffData();
void deleteStaffData(staff loggedInStaff);
void displayActionHistory();
void searchID();
void searchIC();
void searchPhoneNumber();
void passwordRecovery();

Member memberarray[100];
void staffMainMenu();
void memberMainMenu();
void registerUser();
void confirmRegistration();
void loginUser();
void forgotPassword();
void addTrain();
void viewTrainSchedule();
void deleteTrain();
void searchTrain();
void modifyTrain();
void filterTrain();
void trainMain();


void loginmember();
void registermember();
int recoverpassword(const char* memberID);
void loginmenu();
void membermenu();
void searchmember();
void modifymember();
void displaymember(const char* memberID);
void travelhistory();

void main() {
	int choice;
	do {
        printf("                 ============================================================================================\n");
        printf("                 | _____          _         _____ _      _        _   _                                     |\n");
        printf("                 ||_   _| __ __ _(_)_ __   |_   _(_) ___| | _____| |_(_)_ __   __ _                         |\n");
        printf("                 |  | || '__/ _` | | '_ \\    | | | |/ __| |/ / _ \\ __| | '_ \\ / _` |                        |\n");
        printf("                 |  | || | | (_| | | | | |   | | | | (__|   <  __/ |_| | | | | (_| |                        |\n");
        printf("                 | _|_||_|  \\__,_|_|_| |_|   |_| |_|\\___|_|\\_\\___|\\__|_|_| |_|\\__, |                        |\n");
        printf("                 |/ ___| _   _ ___| |_ ___ _ __ ___                           |___/                         |\n");
        printf("                 |\\___ \\| | | / __| __/ _ \\ '_ ` _ \\                                                        |\n");
        printf("                 | ___) | |_| \\__ \\ ||  __/ | | | | |                                                       |\n");
        printf("                 ||____/ \\__, |___/\\__\\___|_| |_| |_|                                                       |\n");
        printf("                 |       |___/                                                                              |\n");

        printf("                 |           o o o o o o o . . .   ______________________________ _____=======_||____       |\n");
        printf("                 |          o      _____           ||                            | |                 |      |\n");
        printf("                 |        .][__n_n_|DD[  ====_____  |                            | |                 |      |\n");
        printf("                 |       >(________|__|_[_________]_|____________________________|_|_________________|      |\n");
        printf("                 |        _/oo OOOOO oo`  ooo   ooo  'o!o!o                  o!o!o` 'o!o         o!o`       |\n");
        printf("                 |        -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-   |\n");
        printf("                 ============================================================================================\n\n");

		printf("                 \tWelcome to Ticketing System!!!                                                      \n");
		printf("                 \t--------------------------------                                                    \n");
		printf("                 \t1. Member mode                                                                      \n");
		printf("                 \t2. Staff mode                                                                       \n");
		printf("                 \t0. Exit                                                                             \n");
		printf("                 \tSelect your choice >  ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			system("cls");
			memberMainMenu();
			break;
		case 2:
			system("cls");
			staffMainMenu();
			break;
		case 0:
			break;
		default:
			system("cls");
			red();
			printf("Invalid choice!!!\n");
			printf("Please Enter Again!!!\n\n");
			black();
		}
	} while (choice != 0);
}

void staffMainMenu() {
	int choice;
	do {


        printf("\t======================================================================================================\n");
        printf("\t|   _____ _         __  __    ____                       _   _                   _    _       _      |\n");
        printf("\t|  / ____| |       / _|/ _|  / __ \\                     | | (_)                 | |  | |     | |     |\n");
        printf("\t| | (___ | |_ __ _| |_| |_  | |  | |_ __   ___ _ __ __ _| |_ _  ___  _ __  ___  | |__| |_   _| |__   |\n");
        printf("\t|  \\___ \\| __/ _` |  _|  _| | |  | | '_ \\ / _ | '__/ _` | __| |/ _ \\| '_ \\/ __| |  __  | | | | '_ \\  |\n");
        printf("\t|  ____) | || (_| | | | |   | |__| | |_) |  __| | | (_| | |_| | (_) | | | \\__ \\ | |  | | |_| | |_) | |\n");
        printf("\t| |_____/ \\__\\__,_|_| |_|    \\____/| .__/ \\___|_|  \\__,_|\\__|_|\\___/|_| |_|___/ |_|  |_|\\__,_|_.__/  |\n");
        printf("\t|                                  | |                                                               |\n");
        printf("\t|                                  |_|                                                               |\n");
        printf("\t=====================================================================================================\n\n");



		printf("\t\t----------------------\n");
		printf("\t\t1. Manage Schedule\n");
		printf("\t\t2. Manage Staff\n");
		printf("\t\t0. Exit\n");
		printf("\t\tEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			system("cls");
			tmain();
			break;

		case 2:
			system("cls");
			staffManage();
			break;
		case 0:
			system("cls");
			break;
		default:
			red();
			printf("Invalid Choice.");
			printf("Enter again\n\n");
			black();
		}
	} while (choice != 0);
}

void memberMainMenu() {
	int choice;
	do {
		printf("\t=================================================================================================================\n\n");
		printf("\t|\t _   .-')       ('-.  _   .-')   .-. .-')    ('-.  _  .-')         ('-. .-.            .-. .-')   \t|\n");
		printf("\t|\t( '.( OO )_   (  OO)( '.( OO ) \\  ( OO ) _(  OO)( \\( -O )       ( OO )  /            \\  ( OO )  \t|\n");
		printf("\t|\t ,--.   ,--.)(,------.,--.   ,--.);-----.\\(,------.,------.       ,--. ,--. ,--. ,--.   ;-----.\\  \t|\n");
		printf("\t|\t |   `.'   |  |  .---'|   .'   | | .-.  | |  .---'|   /. '      |  | |  | |  | |  |   | .-.  |  \t|\n");
		printf("\t|\t |         |  |  |    |         | | '-' /)|  |    |  /  | |      |   .|  | |  | | .-') | '-' /) \t|\n");
		printf("\t|\t |  |'.'|  | (|  '--. |  |'.'|  | | .-. `.(|  '--. |  |.' |      |       | |  ||( OO )| .-. `.  \t|\n");
		printf("\t|\t |  |   |  |  |  .--' |  |   |  | | |  \\  ||  .--' |  .  '.'      |  .-.  | |  | | `-' /| |  \\  | \t|\n");
		printf("\t|\t |  |   |  |  |  `---.|  |   |  | | '--'  /|  `---.|  |\\  \\       |  | |  |('  '-'(_.-' | '--'  / \t|\n");
		printf("\t|\t `--'   `--'  ------'--'   `--' `------' ------'--' '--'      `--' `--'  `-----'    `------'  \t|\n");
		printf("\n\t=================================================================================================================\n\n");

		printf("\t-----------------------------------------------------------------------------------------------------------------\n\n");
		printf("\t\t\t\t\t\t------------------------------------\n");
		printf("\t\t\t\t\t\t|1. Member                          |\n");
		printf("\t\t\t\t\t\t|2. Ticket Bookings                 |\n");
		printf("\t\t\t\t\t\t|0. Exit                            |\n");
		printf("\t\t\t\t\t\t------------------------------------\n");
		printf("\t\t\t\t\t\t------------------------------------\n");
		printf("\t\t\t\t\t\t Enter your choice: ");
		scanf("%d", &choice);
		printf("\t\t\t\t\t\t------------------------------------\n");

		switch (choice) {
		case 1:
			system("cls");
			loginmenu();
			break;
		case 2:
			system("cls");
			bookingMain();
			break;
		case 0:
			system("cls");
			break;
		default:

			printf("Invalid Choice.");
			printf("Enter again\n\n");

		}
	} while (choice != 0);
}

struct Booking {
    char bookingID[15];
    char memberID[15];
    char trainID[15];
    char bookingDate[15];
    char departureDate[15];
    char seatNumber[5][5];
    char coach[10];
    int quantity;
    char bankName[20];
    char bankNumber[20];
    float amount;
    char status[20];
    char memberName[30];
    char memberIc[20];
    char memberPhone[20];
    char password[30];
    char password_recovery[30];
};


void printGreen(const char* text) {
    printf("\033[0;32m%s\033[0m", text);
}

void printRed(const char* text) {
    printf("\033[1;31m%s\033[0m", text);
}

void printCyan(const char* text) {
    printf("\033[1;36m%s\033[0m", text);
}

void printBlue(const char* text) {
    printf("\033[1;34m%s\033[0m", text);
}


bool validateDate(const char* date) {

    if (strlen(date) != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;


    int year, month, day;
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3)
        return false;

    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}
bool validateIC(const char* ic) {
    int i = 0;


    while (ic[i] != '\0') {
        if (!isdigit(ic[i]))
            return false;
        i++;
    }

    if (i != 12)
        return false;

    return true;
}

bool validatePhoneNumber(const char* phoneNumber) {
    int i = 0;
    while (phoneNumber[i] != '\0') {
        if (!isdigit(phoneNumber[i]))
            return false;
        i++;
    }

    if (i != 10 && (i < 9 || i > 10))
        return false;
    if (i == 10 && !(phoneNumber[0] == '0' && phoneNumber[1] == '1'))
        return false;
    return true;
}
bool isSeatAvailable(const char(*seatNumbers)[5], int quantity, const char* newSeat) {
    for (int i = 0; i < quantity; i++) {
        if (strcmp(seatNumbers[i], newSeat) == 0) {
            return false;
        }
    }
    return true;
}


void bookingregister() {

    struct Booking member;
    FILE* registermember;
    registermember = fopen("bookings.dat", "rb");

    if (!registermember) {
        printf("Error opening file.\n");
        exit(-1);
    }


    printf("                         _                                _     _            \n");
    printf("                          | |                              (_)   | |           \n");
    printf("  _ __ ___   ___ _ __ ___ | |__   ___ _ __   _ __ ___  __ _ _ ___| |_ ___ _ __ \n");
    printf(" | '_ ` _ \\ / _ | '_ ` _ \\| '_ \\ / _ | '__| | '__/ _ \\/ _` | / __| __/ _ | '__|\n");
    printf(" | | | | | |  __| | | | | | |_) |  __| |    | | |  __| (_| | \\__ | ||  __| |   \n");
    printf(" |_| |_| |_|\\___|_| |_| |_|_.__/ \\___|_|    |_|  \\___|\\__, |_|___/\\__\\___|_|   \n");
    printf("                                                       __/ |                   \n");
    printf("                                                      |___/                    \n");



    int exists;
    do {
        exists = 0;
        printf("Enter Your Member ID (MXXXXXXX): ");
        scanf("%s", member.memberID);
        rewind(stdin);

        if (strlen(member.memberID) != 8 || strncmp(member.memberID, "M", 1) != 0) {
            printRed("Invalid Member Format.\n\n");

        }

        struct Booking temp;

        rewind(registermember);

        while (fread(&temp, sizeof(struct Booking), 1, registermember) == 1) {
            if (strncmp(temp.memberID, member.memberID, 8) == 0) {
                printRed("Member ID Already Exists. Please Enter Again.\n\n");
                exists = 1;
                break;
            }
        }

    } while (strlen(member.memberID) != 8 || strncmp(member.memberID, "M", 1) != 0 || exists);





    fclose(registermember);


    registermember = fopen("bookings.dat", "ab");

    if (!registermember) {
        printf("Error opening file for writing.\n");
        exit(-1);
    }


    do {
        printf("\nEnter Your Password (20 MAX)   : ");
        scanf("%[^\n]", member.password);
        rewind(stdin);

        if (strlen(member.password) > 20) {
            printRed("Password Too Long,Please Enter A Shorter Password\n");
        }

    } while (strlen(member.password) > 20);

    printCyan("\nWhat Is Your Favorite Movie?\n");
    printf("Enter Your Answer              :");
    scanf("%[^\n]", member.password_recovery);
    rewind(stdin);





    fwrite(&member, sizeof(struct Booking), 1, registermember);
    fclose(registermember);
    printGreen("\nRegistration Successful.\n");
    printCyan("\nPress Enter To Continue...");
    getchar();

}

void bookinglogin() {
    system("cls");
    FILE* memberlogin;
    char memberID[15];
    char memberpass[20];
    int memberchoice;
    struct Booking member;

    memberlogin = fopen("bookings.dat", "rb");

    if (!memberlogin) {
        printf("Error opening file\n");
        exit(-1);
    }

#include <stdio.h>


    printf("                           _                 _             _       \n");
    printf("                          | |               | |           (_)      \n");
    printf("  _ __ ___   ___ _ __ ___ | |__   ___ _ __  | | ___   __ _ _ _ __  \n");
    printf(" | '_ ` _ \\ / _ | '_ ` _ \\| '_ \\ / _ | '__| | |/ _ \\ / _` | | '_ \\ \n");
    printf(" | | | | | |  __| | | | | | |_) |  __| |    | | (_) | (_| | | | | |\n");
    printf(" |_| |_| |_|\\___|_| |_| |_|_.__/ \\___|_|    |_|\\___/ \\__, |_|_| |_|\n");
    printf("                                                      __/ |        \n");
    printf("                                                     |___/         \n");



    printf("\nEnter your memberID: ");
    scanf("%s", memberID);

    int found = 0;

    while (fread(&member, sizeof(struct Booking), 1, memberlogin) != 0) {
        if (strcmp(memberID, member.memberID) == 0) {
            found = 1;
            printGreen("\nMember ID found\n");
            rewind(stdin);
            printf("\nEnter your password: ");
            scanf("%[^\n]", memberpass);
            rewind(stdin);

            if (strcmp(memberpass, member.password) == 0) {
                printGreen("\nLogin successful\n");
                fclose(memberlogin);

                printCyan("\nPress Any Key To Continue...");
                getchar();
                system("cls");
                bookingMenu(memberID);

            }
            else {
                printRed("\nInvalid password\n");
                printf("\nEnter 1 To Recover Password: ");

                scanf("%d", &memberchoice);
                rewind(stdin);

                switch (memberchoice) {
                case 1:
                    fclose(memberlogin);
                    bookingrecovery(memberID);
                    break;

                default:
                    printRed("\nInvalid Choice\n");
                    bookingMain();

                }
            }
        }

    }
    if (found == 0) {
        printRed("Invalid Member ID\n");
        printCyan("\nPress Enter To Continue...");
        getchar();
        getchar();

    }

    fclose(memberlogin);


}


int bookingrecovery(const char* memberID) {
    system("cls");
    FILE* recover;
    FILE* temp;
    char recoverypass[20];
    struct Booking member;
    int found = 0;

    recover = fopen("bookings.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (!recover || !temp) {
        printf("Error Opening Files\n");
        exit(-1);
    }


    printf("                                                                                   _ \n");
    printf("                                                                                    | |\n");
    printf("  _ __ ___  ___ _____   _____ _ __ _   _   _ __   __ _ ___ _____      _____  _ __ __| |\n");
    printf(" | '__/ _ \\/ __/ _ \\ \\ / / _ | '__| | | | | '_ \\ / _` / __/ __\\ \\ /\\ / / _ \\| '__/ _` |\n");
    printf(" | | |  __| (_| (_) \\ V /  __| |  | |_| | | |_) | (_| \\__ \\__ \\\\ V  V / (_) | | | (_| |\n");
    printf(" |_|  \\___|\\___\\___/ \\_/ \\___|_|   \\__, | | .__/ \\__,_|___|___/ \\_/\\_/ \\___/|_|  \\__,_|\n");
    printf("                                    __/ | | |                                           \n");
    printf("                                   |___/  |_|                                           \n");




    printBlue("\nWhat Is Your Favorite Movie?\n");
    printf("Enter Your Answer              :");
    scanf("%[^\n]", recoverypass);
    rewind(stdin);

    while (fread(&member, sizeof(struct Booking), 1, recover) == 1) {
        if (strcmp(recoverypass, member.password_recovery) == 0 && strcmp(memberID, member.memberID) == 0) {
            found = 1;
            printCyan("\nEnter Your New Password        : ");
            scanf("%s", member.password);
            rewind(stdin);
            printGreen("\nPassword Recovery Successful\n");
            printCyan("\n\nPress Enter To Continue...");
            getchar();
            fwrite(&member, sizeof(struct Booking), 1, temp);
            break;
        }
        else {
            fwrite(&member, sizeof(struct Booking), 1, temp);
        }
    }


    fclose(recover);
    fclose(temp);

    if (found == 0) {
        printRed("\nInvalid Recovery Password or Member ID\n");
        remove("temp.dat");
        printCyan("\n\nPress Enter To Continue...");
        getchar();
        return 0;
    }

    remove("bookings.dat");
    rename("temp.dat", "bookings.dat");
    return 1;
}


int bookingMain() {

    int choice;

    do {




        printf("  _             _         _                 _    _             \n");
        printf(" | |           (_)       | |               | |  (_)            \n");
        printf(" | |_ _ __ __ _ _ _ __   | |__   ___   ___ | | ___ _ __   __ _ \n");
        printf(" | __| '__/ _` | | '_ \\  | '_ \\ / _ \\ / _ \\| |/ | | '_ \\ / _` |\n");
        printf(" | |_| | | (_| | | | | | | |_) | (_) | (_) |   <| | | | | (_| |\n");
        printf("  \\__|_|  \\__,_|_|_| |_| |_.__/ \\___/ \\___/|_|\\_|_|_| |_|\\__, |\n");
        printf("                                                          __/ |\n");
        printf("                                                         |___/ \n");






        printf("\n1. Register\n2. Login\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");
            bookingregister();
            system("cls");
            break;
        case 2:
            system("cls");
            bookinglogin();
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printRed("\nInvalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (choice != 0);

    return 0;
}


void printCoach(int seats) {
    if (seats <= 50) {
        printf("\n");
        printf("========================================================\n");
        printf("|SEAT NUMBER :    01 02 03 04 05 06 07 08 09 10         |\n");
        printf("|                                                       |\n");
        printf("|A                 O  O  O  O  O  O  O  O  O  O         |\n");
        printf("|                                                       |\n");
        printf("|B                 O  O  O  O  O  O  O  O  O  O         |\n");
        printf("|                                                       |\n");
        printf("|C                 O  O  O  O  O  O  O  O  O  O         |\n");
        printf("|                                                       |\n");
        printf("|D                 O  O  O  O  O  O  O  O  O  O         |\n");
        printf("|                                                       |\n");
        printf("|E                 O     O     O     O     O            |\n");
        printf("|                                                       |\n");
        printf("|F                 O     O     O     O     O            |\n");
        printf("|                                                       |\n");
        printf("========================================================\n");
    }
    else if (seats <= 100) {
        printf("\n");
        printf("==================================================================================================\n");
        printf("|SEAT NUMBER :    01 02 03 04 05 06 07 08 09 10   11 12 13 14 15 16 17 18 19 20                   |\n");
        printf("|                                                                                                 |\n");
        printf("|A                 O  O  O  O  O  O  O  O  O  O    O  O  O  O  O  O  O  O  O  O                   |\n");
        printf("|                                                                                                 |\n");
        printf("|B                 O  O  O  O  O  O  O  O  O  O    O  O  O  O  O  O  O  O  O  O                   |\n");
        printf("|                                                                                                 |\n");
        printf("|C                 O  O  O  O  O  O  O  O  O  O    O  O  O  O  O  O  O  O  O  O                   |\n");
        printf("|                                                                                                 |\n");
        printf("|D                 O  O  O  O  O  O  O  O  O  O    O  O  O  O  O  O  O  O  O  O                   |\n");
        printf("|                                                                                                 |\n");
        printf("|E                 O     O     O     O     O       O     O     O     O     O                      |\n");
        printf("|                                                                                                 |\n");
        printf("|F                 O     O     O     O     O       O     O     O     O     O                      |\n");
        printf("|                                                                                                 |\n");
        printf("==================================================================================================\n");
    }
    printf("A - D is ECONOMY CLASS \n");
    printf("E - F is FIRST CLASS \n\n");

}



bool validateAccountNumber(const char* accountNumber) {
    int length = strlen(accountNumber);

    if (length != 10) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (!isdigit(accountNumber[i])) {
            return false;
        }
    }
    return true;
}




void selectSeat(struct Booking* bookings, const char* trainID) {
    system("cls");
    FILE* schedule;
    schedule = fopen("schedule.txt", "r");
    if (schedule == NULL) {
        printf("Unable to open the schedule file.\n");
        exit(-1);
    }

    Train train;
    int match = 0;
    printf("\n\t\t\t\t\t   <<< TRAIN SCHEDULE >>>\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| ID       | Departure Station | Arrival Station | Departure Time | Arrival Time  | Date      | Available Seats | Economy Price | First Class Price    |\n");
    printf("=======================================================================================================================================================\n");

    while (fscanf(schedule, " %[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%lf|%lf\n", train.id, train.departureStation, train.arriveStation, train.departureTime, train.arrivalTime, train.date, &train.availableSeats, &train.economyPrice, &train.firstClassPrice) != EOF) {

        if (strcmp(train.id, trainID) == 0) {
            printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("| %-8s | %-17s | %-15s | %-14s | %-12s | %-10s | %-15d | %-13.2lf | %-16.2lf     |\n", train.id, train.departureStation, train.arriveStation, train.departureTime, train.arrivalTime, train.date, train.availableSeats, train.economyPrice, train.firstClassPrice);
            printf("=======================================================================================================================================================\n");
            match = 1;
            printCoach(train.availableSeats);


            int coachAvailableSeats = train.availableSeats;
            do {
                printf("Enter Coach (A/B/C/D/E/F)  : ");
                scanf(" %s", bookings->coach);
                rewind(stdin);
                printf("\n");

                if (strcmp(bookings->coach, "A") != 0 && strcmp(bookings->coach, "B") != 0 && strcmp(bookings->coach, "C") != 0 && strcmp(bookings->coach, "D") != 0 && strcmp(bookings->coach, "E") != 0 && strcmp(bookings->coach, "F") != 0) {
                    printRed("Invalid Coach, Please Enter A, B, C, D, E, or F!\n");
                    printf("\n");
                }
                else if (strcmp(bookings->coach, "A") == 0 || strcmp(bookings->coach, "B") == 0 || strcmp(bookings->coach, "C") == 0 || strcmp(bookings->coach, "D") == 0) {

                    do {
                        printf("Enter Quantity             : ");
                        scanf("%d", &bookings->quantity);
                        rewind(stdin);
                        printf("\n");

                        if (bookings->quantity < 1 || bookings->quantity > 4) {
                            printRed("Invalid quantity. Please enter a value between 1 and 4.\n");
                            printf("\n");
                        }
                    } while (bookings->quantity < 1 || bookings->quantity > 4);



                    for (int i = 0; i < bookings->quantity; i++) {
                        printf("Enter Seat Number %d        : ", i + 1);
                        scanf("%s", bookings->seatNumber[i]);
                        rewind(stdin);
                        printf("\n");

                        int seatNum;
                        sscanf(bookings->seatNumber[i], "%d", &seatNum);
                        if (coachAvailableSeats == 100 && (seatNum < 1 || seatNum > 10)) {
                            printRed("Invalid seat number. Please enter a number between 1 and 10.\n");
                            printf("\n");
                            i--;
                        }
                        else if (coachAvailableSeats == 50 && (seatNum < 1 || seatNum > 10)) {
                            printRed("Invalid seat number. Please enter a number between 1 and 10.\n");
                            printf("\n");
                            i--;
                        }
                    }
                }
                else if (strcmp(bookings->coach, "E") == 0 || strcmp(bookings->coach, "F") == 0) {

                    do {
                        printf("Enter Quantity             : ");
                        scanf("%d", &bookings->quantity);
                        rewind(stdin);
                        printf("\n");

                        if (bookings->quantity < 1 || bookings->quantity > 2) {
                            printRed("Invalid quantity. Please enter a value between 1 and 2.\n");
                            printf("\n");
                        }
                    } while (bookings->quantity < 1 || bookings->quantity > 2);


                    for (int i = 0; i < bookings->quantity; i++) {
                        printf("Enter Seat Number %d        : ", i + 1);
                        scanf("%4s", bookings->seatNumber[i]);
                        rewind(stdin);
                        printf("\n");


                        int seatNum;
                        sscanf(bookings->seatNumber[i], "%d", &seatNum);
                        if (coachAvailableSeats == 100 && (seatNum < 1 || seatNum > 20 || seatNum % 2 == 0)) {
                            printRed("Invalid seat number. Please enter an odd number between 1 and 20.\n");
                            printf("\n");
                            i--;
                        }
                        else if (coachAvailableSeats == 50 && (seatNum < 1 || seatNum > 10 || seatNum % 2 == 0)) {
                            printRed("Invalid seat number. Please enter an odd number between 1 and 10.\n");
                            printf("\n");
                            i--;
                        }
                    }
                }

            } while (strcmp(bookings->coach, "A") != 0 && strcmp(bookings->coach, "B") != 0 && strcmp(bookings->coach, "C") != 0 && strcmp(bookings->coach, "D") != 0 && strcmp(bookings->coach, "E") != 0 && strcmp(bookings->coach, "F") != 0);

            break;
        }
    }

    if (match == 0) {
        printRed("Train ID not found in the schedule.\n");
    }

    fclose(schedule);
}



void payment(struct Booking* bookings, double price01, double price02, int quantity) {
    system("cls");
    double total = 0.0;

    printf("  ____   ____   ____  _  _______ _   _  _____    _____ _    _ __  __ __  __          _______     __\n");
    printf(" |  _ \\ / __ \\ / __ \\| |/ |_   _| \\ | |/ ____|  / ____| |  | |  \\/  |  \\/  |   /\\   |  __ \\ \\   / /\n");
    printf(" | |_) | |  | | |  | | ' /  | | |  \\| | |  __  | (___ | |  | | \\  / | \\  / |  /  \\  | |__) \\ \\_/ / \n");
    printf(" |  _ <| |  | | |  | |  <   | | | . ` | | |_ |  \\___ \\| |  | | |\\/| | |\\/| | / /\\ \\ |  _  / \\   /  \n");
    printf(" | |_) | |__| | |__| | . \\ _| |_| |\\  | |__| |  ____) | |__| | |  | | |  | |/ ____ \\| | \\ \\  | |   \n");
    printf(" |____/ \\____/ \\____/|_|\\_|_____|_| \\_|\\_____| |_____/ \\____/|_|  |_|_|  |_/_/    \\_|_|  \\_\\ |_|   \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");





    printf("\nTrain ID                  : %s\n", bookings->trainID);
    printf("Coach                     : %s\n", bookings->coach);
    printf("Quantity                  : %d\n", quantity);


    if (strcmp(bookings->coach, "A") == 0 || strcmp(bookings->coach, "B") == 0 || strcmp(bookings->coach, "C") == 0 || strcmp(bookings->coach, "D") == 0) {

        printf("Class                     : Economy\n");
        printf("Price per Ticket          : RM %.2lf\n", price01);
    }
    else if (strcmp(bookings->coach, "E") == 0 || strcmp(bookings->coach, "F") == 0) {

        printf("Class                     : First\n");
        printf("Price per Ticket          : RM %.2lf\n", price02);
    }


    total = quantity * (strcmp(bookings->coach, "A") == 0 || strcmp(bookings->coach, "B") == 0 || strcmp(bookings->coach, "C") == 0 || strcmp(bookings->coach, "D") == 0 ? price01 : price02);
    printf("Total Amount Due          : RM %.2lf\n", total);
    bookings->amount = total;


    printf("\nPayment Details:\n");
    printf("==============================================================================================\n");


    printf("Enter Bank Name           : ");
    scanf("%[^\n]", bookings->bankName);
    rewind(stdin);

    do {
        printf("Enter Bank Account Number : ");
        scanf("%s", bookings->bankNumber);
        rewind(stdin);

        if (!validateAccountNumber(bookings->bankNumber)) {
            printRed("Invalid account number. Please enter a 10-digit number.\n");
        }
    } while (!validateAccountNumber(bookings->bankNumber));




    printf("\nEnter 'Y' to confirm payment or 'N' to cancel: ");
    char confirm;
    scanf("%c", &confirm);
    rewind(stdin);
    if (confirm == 'Y' || confirm == 'y') {
        printGreen("\nPayment Confirmed. Thank you!\n");
        printCyan("\nBooking added successfully.\n");
        strcpy(bookings->status, "Booked");
    }
    else if (confirm == 'N' || confirm == 'n') {
        printRed("\nPayment Canceled. Booking Remains Pending.\n");
        strcpy(bookings->status, "Pending");
    }



}


void payPending(const char* memberID) {

    FILE* ticket;
    ticket = fopen("bookings.dat", "rb");
    if (ticket == NULL) {
        printf("Unable to open the file.\n");
        exit(-1);
    }
    struct Booking tempBooking;
    bool bookingModified = false;

    FILE* tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(ticket);
        exit(-1);
    }


    printf("  _____    __     ____  __ ______ _   _ _______ \n");
    printf(" |  __ \\ /\\ \\   / |  \\/  |  ____| \\ | |__   __|\n");
    printf(" | |__) /  \\ \\_/ /| \\  / | |__  |  \\| |  | |   \n");
    printf(" |  ___/ /\\ \\   / | |\\/| |  __| | . ` |  | |   \n");
    printf(" | |  / ____ \\ |  | |  | | |____| |\\  |  | |   \n");
    printf(" |_| /_/    \\_|_|  |_|  |_|______|_| \\_|  |_|   \n");
    printf("                                                \n");


    int found = 0;

    while (fread(&tempBooking, sizeof(struct Booking), 1, ticket) == 1) {
        if (strcmp(tempBooking.memberID, memberID) == 0 && strcmp(tempBooking.status, "Pending") == 0) {
            found = 1;
            printf("===============================================================================================================================================================================\n");
            printf("| Booking ID | Member ID |Train ID | Booking Date  | Departure Date| Bank Name            | Bank Number   | Amount  | Status     | Coach   | Quantity | Seat(s)                \n");
            printf("===============================================================================================================================================================================\n");

            printf("| %-10s | %-9s |%-8s | %-13s | %-13s |", tempBooking.bookingID, tempBooking.memberID, tempBooking.trainID,
                tempBooking.bookingDate, tempBooking.departureDate);


            printf(" %-20s | %-13s | %-7.2f | %-10s | %-7s | %-8d |",
                tempBooking.bankName, tempBooking.bankNumber, tempBooking.amount, tempBooking.status,
                tempBooking.coach, tempBooking.quantity);


            for (int i = 0; i < tempBooking.quantity; i++) {
                printf("%-3s    ", tempBooking.seatNumber[i]);
            }
            printf("\n");

            printf("\nPayment Details:\n");
            printf("==============================================================================================\n");

            printf("Enter Bank Name           : ");
            scanf("%s", tempBooking.bankName);
            rewind(stdin);
            do {
                printf("Enter Bank Account Number : ");
                scanf("%s", tempBooking.bankNumber);
                rewind(stdin);

                if (!validateAccountNumber(tempBooking.bankNumber)) {
                    printRed("Invalid account number. Please enter a 10-digit number.\n");
                }
            } while (!validateAccountNumber(tempBooking.bankNumber));

            char confirm;
            do {
                printf("\nEnter 'Y' to confirm payment or 'N' to cancel: ");
                scanf(" %c", &confirm);
                if (confirm != 'Y' && confirm != 'N') {
                    printf("Invalid input. Please enter 'Y' or 'N'.\n");
                }
            } while (confirm != 'Y' && confirm != 'N');

            if (confirm == 'Y' || confirm == 'y') {
                printGreen("\nPayment Confirmed. Thank you!\n");
                strcpy(tempBooking.status, "Booked");
                bookingModified = true;
            }
            else {
                printRed("\nPayment Canceled. Booking not completed.\n");
                strcpy(tempBooking.status, "Pending");
            }

        }
        fwrite(&tempBooking, sizeof(struct Booking), 1, tempFile);
    }
    fclose(ticket);
    fclose(tempFile);

    remove("bookings.dat");
    rename("temp.dat", "bookings.dat");

    if (found == 0) {
        printGreen("\nNo payment needs to be made.");
    }
    printCyan("\nPress Enter To Continue...");
    getchar();
    getchar();

}



void addBooking(const char* memberID) {
    struct Booking bookings;




    FILE* schedule;
    schedule = fopen("schedule.txt", "r");
    if (schedule == NULL) {
        printf("Unable to open the schedule file.\n");
        exit(-1);
    }

    Train train;


    printf("           _____  _____    ____   ____   ____  _  _______ _   _  _____ \n");
    printf("     /\\   |  __ \\|  __ \\  |  _ \\ / __ \\ / __ \\| |/ |_   _| \\ | |/ ____|\n");
    printf("    /  \\  | |  | | |  | | | |_) | |  | | |  | | ' /  | | |  \\| | |  __ \n");
    printf("   / /\\ \\ | |  | | |  | | |  _ <| |  | | |  | |  <   | | | . ` | | |_ |\n");
    printf("  / ____ \\| |__| | |__| | | |_) | |__| | |__| | . \\ _| |_| |\\  | |__| |\n");
    printf(" /_/    \\_|_____/|_____/  |____/ \\____/ \\____/|_|\\_|_____|_| \\_|\\_____|\n");
    printf("                                                                       \n");
    printf("                                                                       \n");




    printGreen("\n                                                            <<<TRAIN SCHEDULE>>>\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| ID      | Departure Station| Arrival Station| Departure Time| Arrival Time | Date      | Available Seats | Economy Price | First Class Price|\n");
    printf("===============================================================================================================================================\n");
    while (fscanf(schedule, " %[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%lf|%lf\n", train.id, train.departureStation, train.arriveStation, train.departureTime, train.arrivalTime, train.date, &train.availableSeats, &train.economyPrice, &train.firstClassPrice) != EOF) {
        printf("| %-6s | %-16s | %-14s | %-13s | %-12s | %-9s | %-15d | %-13.2lf | %-16.2lf |\n", train.id, train.departureStation, train.arriveStation, train.departureTime, train.arrivalTime, train.date, train.availableSeats, train.economyPrice, train.firstClassPrice);
    }

    int exists;
    do {

        FILE* ticket;
        ticket = fopen("bookings.dat", "rb");
        if (ticket == NULL) {
            printf("Unable to open the bookings file.\n");
            exit(-1);
        }
        exists = 0;
        printf("\nEnter Booking ID (B12345)      :");
        scanf("%s", bookings.bookingID);
        rewind(stdin);

        if (strlen(bookings.bookingID) != 6 || strncmp(bookings.bookingID, "B", 1) != 0) {
            printRed("Invalid Booking Format.\n\n");
            exists = 1;

        }

        struct Booking old;

        rewind(ticket);

        while (fread(&old, sizeof(struct Booking), 1, ticket) == 1) {
            if (strcmp(old.bookingID, bookings.bookingID) == 0) {
                printRed("Booking ID Already Exists. Please Enter Again.\n\n");
                exists = 1;
                break;
            }
        }
        fclose(ticket);
    } while (exists);


    FILE* ticket;
    ticket = fopen("bookings.dat", "ab");
    if (ticket == NULL) {
        printf("Unable to open the bookings file.\n");
        exit(-1);
    }


    rewind(schedule);
    printf("\n");
    int match;
    do {
        match = 0;

        printf("\nEnter Train ID                 :");
        if (scanf("%s", bookings.trainID) != 1) {
            printRed("Invalid input, please try again.\n");
            rewind(stdin);
        }
        else {
            rewind(schedule);
            while (fscanf(schedule, " %[^|]| %*[^|]| %*[^|]| %*[^|]| %*[^|]| %*[^|]| %*d| %*lf| %*lf\n", train.id) == 1) {
                if (strcmp(bookings.trainID, train.id) == 0) {
                    match = 1;
                    break;
                }
            }
            if (match == 0) {
                printRed("Invalid Train ID, please enter again!\n");
            }
        }
    } while (match == 0);

    printf("\n");
    do {
        rewind(stdin);
        printf("\nEnter Your Name (20 MAX)       :");
        scanf("%[^\n]", bookings.memberName);
        rewind(stdin);

        if (strlen(bookings.memberName) > 20) {
            printRed("Name Too Long,Enter A Shorter Name\n");
        }
    } while (strlen(bookings.memberName) > 20);

    printf("\n");
    printf("Enter IC                       : ");
    scanf("%s", bookings.memberIc);
    rewind(stdin);

    while (!validateIC(bookings.memberIc)) {

        printRed("\nInvalid IC. IC must be 12 digits. Please enter again.\n");
        printf("\nEnter IC                       :");
        scanf("%s", bookings.memberIc);
        rewind(stdin);


    }



    printf("\nEnter Phone                    :");
    scanf("%s", bookings.memberPhone);
    rewind(stdin);

    while (!validatePhoneNumber(bookings.memberPhone)) {
        printRed("\nInvalid phone number. Must be 9 to 10 digits long and start with '01'.\n");
        printf("\nEnter Phone                    :");
        scanf("%s", bookings.memberPhone);
        rewind(stdin);
    }



    printf("\nEnter Booking Date (YYYY-MM-DD):");
    scanf("%s", bookings.bookingDate);
    rewind(stdin);

    while (!validateDate(bookings.bookingDate)) {
        printRed("Invalid date format. Please enter the date in YYYY-MM-DD format.\n");
        printf("\nEnter Booking Date (YYYY-MM-DD): ");
        scanf("%s", bookings.bookingDate);
        rewind(stdin);

    }

    strcpy(bookings.memberID, memberID);

    strcpy(bookings.departureDate, train.date);

    selectSeat(&bookings, bookings.trainID);

    payment(&bookings, train.economyPrice, train.firstClassPrice, bookings.quantity);



    fwrite(&bookings, sizeof(struct Booking), 1, ticket);
    fclose(schedule);
    fclose(ticket);



    printBlue("\nPress Enter To Continue...");
    getchar();
}

void displayBooking(const char* memberID)
{
    FILE* ticket;
    ticket = fopen("bookings.dat", "rb");
    if (ticket == NULL) {
        printf("Unable to open the file.\n");
        exit(-1);
    }

    struct Booking tempBooking;


    printf("          _      _        ____   ____   ____  _  _______ _   _  _____ \n");
    printf("     /\\   | |    | |      |  _ \\ / __ \\ / __ \\| |/ |_   _| \\ | |/ ____|\n");
    printf("    /  \\  | |    | |      | |_) | |  | | |  | | ' /  | | |  \\| | |  __ \n");
    printf("   / /\\ \\ | |    | |      |  _ <| |  | | |  | |  <   | | | . ` | | |_ |\n");
    printf("  / ____ \\| |____| |____  | |_) | |__| | |__| | . \\ _| |_| |\\  | |__| |\n");
    printf(" /_/    \\_|______|______| |____/ \\____/ \\____/|_|\\_|_____|_| \\_|\\_____|\n");
    printf("                                                                       \n");
    printf("                                                                       \n");






    printf("\n");
    printf("===============================================================================================================================================================================\n");
    printf("| Booking ID | Member ID |Train ID | Booking Date  | Departure Date| Bank Name            | Bank Number   | Amount  | Status     | Coach   | Quantity | Seat(s)                \n");
    printf("===============================================================================================================================================================================\n");
    while (fread(&tempBooking, sizeof(struct Booking), 1, ticket) == 1) {
        if (strcmp(tempBooking.memberID, memberID) == 0 && (strcmp(tempBooking.status, "Pending") == 0 || strcmp(tempBooking.status, "Booked") == 0 || strcmp(tempBooking.status, "Canceled") == 0)) {

            printf("| %-10s | %-9s |%-8s | %-13s | %-13s |", tempBooking.bookingID, tempBooking.memberID, tempBooking.trainID,
                tempBooking.bookingDate, tempBooking.departureDate);


            printf(" %-20s | %-13s | %-7.2f | %-10s | %-7s | %-8d |",
                tempBooking.bankName, tempBooking.bankNumber, tempBooking.amount, tempBooking.status,
                tempBooking.coach, tempBooking.quantity);


            for (int i = 0; i < tempBooking.quantity; i++) {
                printf("%-3s    ", tempBooking.seatNumber[i]);
            }
            printf("\n");
        }
    }
    printf("===============================================================================================================================================================================\n");


    fclose(ticket);
    printCyan("Press Enter To Continue...");
    getchar();
    getchar();
}


void modifyBooking(const char* memberID) {
    FILE* ticket;
    FILE* tempFile;
    ticket = fopen("bookings.dat", "rb");
    tempFile = fopen("temp.dat", "wb");
    if (ticket == NULL || tempFile == NULL) {
        printf("Unable to open the file(s).\n");
        exit(-1);
    }

    char bookingID[15];
    int found = 0;

    printf("Enter Booking ID to modify: ");
    scanf("%s", bookingID);

    struct Booking tempBooking;


        printf(" __  __  ____  _____ _____ ________     __  ____   ____   ____  _  _______ _   _  _____ \n");
        printf("|  \\/  |/ __ \\|  __ \\_   _|  ____\\ \\   / / |  _ \\ / __ \\ / __ \\| |/ |_   _| \\ | |/ ____|\n");
        printf("| \\  / | |  | | |__) || | | |__   \\ \\_/ /  | |_) | |  | | |  | | ' /  | | |  \\| | |  __ \n");
        printf("| |\\/| | |  | |  ___/ | | |  __|   \\   /   |  _ <| |  | | |  | |  <   | | | . ` | | |_ |\n");
        printf("| |  | | |__| | |     _| |_| |       | |    | |_) | |__| | |__| | . \\ _| |_| |\\  | |__| |\n");
        printf("|_|  |_|\\____/|_|    |_____|_|       |_|    |____/ \\____/ \\____/|_|\\_|_____|_| \\_|\\_____|\n");
        printf("                                                                                         \n");
        printf("                                                                                         \n");

    

    while (fread(&tempBooking, sizeof(struct Booking), 1, ticket) == 1) {
        if (strcmp(tempBooking.bookingID, bookingID) == 0 && strcmp(tempBooking.memberID, memberID) == 0) {
            found = 1;
            printBlue("\nBooking found. \n");
            printf("=====================================\n");
            printf("Train ID                 : %s\n", tempBooking.trainID);
            printf("Member ID                : %s\n", tempBooking.memberID);
            printf("Booking Date             : %s\n", tempBooking.bookingDate);
            printf("Departure Date           : %s\n", tempBooking.departureDate);
            printf("Seat Number(s)           : ");
            for (int i = 0; i < tempBooking.quantity; i++) {
                printf("%s ", tempBooking.seatNumber[i]);
            }
            printf("\nCoach                    : %s\n", tempBooking.coach);
            printf("Quantity                 : %d\n", tempBooking.quantity);

            printBlue("\nWhat do you want to modify?\n");
            printf("1. Seat Number(s)\n");
            printf("2. Coach\n");
            printf("\nEnter your choice               : ");
            int choice;
            scanf("%d", &choice);
            switch (choice) {
            case 1: {
                for (int i = 0; i < tempBooking.quantity; i++) {
                    char newSeat[5];
                    int seatNum;

                    do {
                        printf("\nEnter new seat number(s)        : ");
                        scanf("%d", &seatNum);


                        sprintf(newSeat, "%d", seatNum);

                        if (!isSeatAvailable(tempBooking.seatNumber, tempBooking.quantity, newSeat)) {
                            printRed("\nSeat is already booked. Enter a different seat number.\n");
                            continue;
                        }


                        if ((strcmp(tempBooking.coach, "A") == 0 || strcmp(tempBooking.coach, "B") == 0 ||
                            strcmp(tempBooking.coach, "C") == 0 || strcmp(tempBooking.coach, "D") == 0) &&
                            (seatNum < 1 || seatNum > 10)) {
                            printRed("\nInvalid seat number. Please enter a number between 1 and 10.\n");
                        }
                        else if ((strcmp(tempBooking.coach, "E") == 0 || strcmp(tempBooking.coach, "F") == 0) &&
                            (seatNum < 1 || seatNum > 10 || seatNum % 2 == 0)) {
                            printRed("\nInvalid seat number. Please enter an odd number between 1 and 10.\n");
                        }
                        else {
                            break;
                        }
                    } while (1);

                    strcpy(tempBooking.seatNumber[i], newSeat);
                }

                printGreen("\nBooking Modified Successfully.\n");
                break;
            }



            case 2: {
                char newCoach[3];
                bool isValid = false;

                do {
                    printf("\nEnter new Coach                 : ");
                    scanf("%s", newCoach);
                    rewind(stdin);


                    if (((strcmp(tempBooking.coach, "A") == 0 || strcmp(tempBooking.coach, "B") == 0 || strcmp(tempBooking.coach, "C") == 0 || strcmp(tempBooking.coach, "D") == 0) &&
                        (strcmp(newCoach, "A") != 0 && strcmp(newCoach, "B") != 0 && strcmp(newCoach, "C") != 0 && strcmp(newCoach, "D") != 0)) ||
                        ((strcmp(newCoach, "E") == 0 || strcmp(newCoach, "F") == 0) &&
                            (strcmp(tempBooking.coach, "E") != 0 && strcmp(tempBooking.coach, "F") != 0))) {
                        printRed("Invalid coach selection. Coaches A, B, C, and D are only allowed when current coach is A, B, C, or D.\n");
                    }
                    else if ((strcmp(tempBooking.coach, "E") == 0 || strcmp(tempBooking.coach, "F") == 0) &&
                        (strcmp(newCoach, "E") != 0 && strcmp(newCoach, "F") != 0)) {
                        printRed("Invalid coach selection.Current coach is E or F.New coach must be E or F.Please enter a different coach.\n");
                    }
                    else {
                        isValid = true;
                    }

                } while (!isValid);

                strcpy(tempBooking.coach, newCoach);
                printGreen("\nBooking Modified Successfully.\n");
                break;
            }
            default:
                printRed("Invalid choice.\n");
                break;
            }


            fwrite(&tempBooking, sizeof(struct Booking), 1, tempFile);

        }
        else {

            fwrite(&tempBooking, sizeof(struct Booking), 1, tempFile);
        }
    }

    if (found==0) {
        printRed("\nBooking not found.\n");
    }

    fclose(ticket);
    fclose(tempFile);


    remove("bookings.dat");

    rename("temp.dat", "bookings.dat");
    printCyan("Press any key to continue...");
    getchar();
    getchar();
}







void cancelBooking(const char* memberID) {
    FILE* ticket;
    FILE* tempFile;
    ticket = fopen("bookings.dat", "rb");
    tempFile = fopen("temp.dat", "wb");
    if (ticket == NULL || tempFile == NULL) {
        printf("Unable to open the file(s).\n");
        exit(-1);
    }

    char bookingID[15];
    int found = 0;



    printf("   _____          _____ _   _  _____ ______ _        ____   ____   ____  _  _______ _   _  _____ \n");
    printf("  / ____|   /\\   / ____| \\ | |/ ____|  ____| |      |  _ \\ / __ \\ / __ \\| |/ |_   _| \\ | |/ ____|\n");
    printf(" | |       /  \\ | |    |  \\| | |    | |__  | |      | |_) | |  | | |  | | ' /  | | |  \\| | |  __ \n");
    printf(" | |      / /\\ \\| |    | . ` | |    |  __| | |      |  _ <| |  | | |  | |  <   | | | . ` | | |_ |\n");
    printf(" | |____ / ____ \\ |____| |\\  | |____| |____| |____  | |_) | |__| | |__| | . \\ _| |_| |\\  | |__| |\n");
    printf("  \\_____/_/    \\_\\_____|_| \\_|\\_____|______|______| |____/ \\____/ \\____/|_|\\_|_____|_| \\_|\\_____|\n");
    printf("                                                                                                  \n");
    printf("                                                                                                  \n");




    printf("\nEnter Booking ID to cancel     : ");
    scanf("%s", bookingID);

    struct Booking tempBooking;

    while (fread(&tempBooking, sizeof(struct Booking), 1, ticket) == 1) {

        if (strcmp(tempBooking.bookingID, bookingID) == 0 && strcmp(tempBooking.memberID, memberID) == 0) {
            found = 1;
            printf("===============================================================================================================================================================================\n");
            printf("| Booking ID | Member ID |Train ID | Booking Date  | Departure Date| Bank Name            | Bank Number   | Amount  | Status     | Coach   | Quantity | Seat(s)                \n");
            printf("===============================================================================================================================================================================\n");
            printf("| %-10s | %-9s |%-8s | %-13s | %-13s |", tempBooking.bookingID, tempBooking.memberID, tempBooking.trainID,
                tempBooking.bookingDate, tempBooking.departureDate);


            printf(" %-20s | %-13s | %-7.2f | %-10s | %-7s | %-8d |",
                tempBooking.bankName, tempBooking.bankNumber, tempBooking.amount, tempBooking.status,
                tempBooking.coach, tempBooking.quantity);


            for (int i = 0; i < tempBooking.quantity; i++) {
                printf("%-3s    ", tempBooking.seatNumber[i]);
            }
            printf("\n");

            printf("===============================================================================================================================================================================\n");

            char confirm;
            do {
                printf("\nEnter 'Y' to confirm cancellation or 'N' to cancel: ");
                scanf(" %c", &confirm);
                if (confirm != 'Y' && confirm != 'N') {
                    printf("Invalid input. Please enter 'Y' or 'N'.\n");
                }
            } while (confirm != 'Y' && confirm != 'N');

            if (confirm == 'Y') {
                printGreen("\nBooking canceled.\n");
                strcpy(tempBooking.status, "Canceled");
            }
            else {
                printBlue("\nCancellation canceled. Booking not canceled.\n");
            }
        }

        fwrite(&tempBooking, sizeof(struct Booking), 1, tempFile);
    }

    if (found == 0) {
        printRed("\nBooking not found.\n");
    }

    fclose(ticket);
    fclose(tempFile);

    remove("bookings.dat");
    rename("temp.dat", "bookings.dat");

    printf("\nPress Enter To Continue...\n");
    getchar();
    getchar();
}

void searchBooking(const char* memberID) {
    FILE* ticket;
    ticket = fopen("bookings.dat", "rb");
    if (ticket == NULL) {
        printf("Unable to open the file.\n");
        exit(-1);
    }

    int searchChoice;


    printf("  _____ ______          _____   _____ _    _   ____   ____   ____  _  _______ _   _  _____ \n");
    printf(" / ____|  ____|   /\\   |  __ \\ / ____| |  | | |  _ \\ / __ \\ / __ \\| |/ |_   _| \\ | |/ ____|\n");
    printf("| (___ | |__    /  \\  | |__) | |    | |__| | | |_) | |  | | |  | | ' /  | | |  \\| | |  __ \n");
    printf(" \\___ \\|  __|  / /\\ \\ |  _  /| |    |  __  | |  _ <| |  | | |  | |  <   | | | . ` | | |_ |\n");
    printf(" ____) | |____ / ____ \\| | \\ \\| |____| |  | | | |_) | |__| | |__| | . \\ _| |_| |\\  | |__| |\n");
    printf("|_____/|______/_/    \\_|_|  \\_\\_____|_|  |_| |____/ \\____/ \\____/|_|\\_|_____|_| \\_|\\_____|\n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");



    printf("Search Booking By:\n");
    printf("1. Booking ID\n");
    printf("2. Train ID\n");
    printf("\nEnter your choice   : ");
    scanf("%d", &searchChoice);
    rewind(stdin);

    struct Booking tempBooking;
    bool found = false;

    switch (searchChoice) {
    case 1: {
        char bookingID[15];
        printf("\nEnter Booking ID    : ");
        scanf("%s", bookingID);
        rewind(stdin);

        printf("\n");

        while (fread(&tempBooking, sizeof(struct Booking), 1, ticket) == 1) {
            if (strcmp(tempBooking.bookingID, bookingID) == 0 && strcmp(tempBooking.memberID, memberID) == 0) {
                found = true;
                printf("===============================================================================================================================================================================\n");
                printBlue("| Booking ID | Member ID |Train ID | Booking Date  | Departure Date| Bank Name            | Bank Number   | Amount  | Status     | Coach   | Quantity | Seat(s)                \n");
                printf("===============================================================================================================================================================================\n");
                printf("| %-10s | %-9s |%-8s | %-13s | %-13s |", tempBooking.bookingID, tempBooking.memberID, tempBooking.trainID,
                    tempBooking.bookingDate, tempBooking.departureDate);


                printf(" %-20s | %-13s | %-7.2f | %-10s | %-7s | %-8d |",
                    tempBooking.bankName, tempBooking.bankNumber, tempBooking.amount, tempBooking.status,
                    tempBooking.coach, tempBooking.quantity);


                for (int i = 0; i < tempBooking.quantity; i++) {
                    printf("%-3s    ", tempBooking.seatNumber[i]);
                }
                printf("\n\n\n");
            }
        }
        printf("===============================================================================================================================================================================\n");

        if (!found) {
            printRed("\nNo bookings found for the specified booking ID.\n");
        }

        break;
    }
    case 2: {
        char trainID[15];
        int maxQuantity = 0;
        printf("\nEnter Train ID      : ");
        scanf("%s", trainID);
        rewind(stdin);
        printf("\n");

        while (fread(&tempBooking, sizeof(struct Booking), 1, ticket) == 1) {
            if (strcmp(tempBooking.trainID, trainID) == 0 && strcmp(tempBooking.memberID, memberID) == 0) {
                found = true;
                printf("===============================================================================================================================================================================\n");
                printf("| Booking ID | Member ID |Train ID | Booking Date  | Departure Date| Bank Name            | Bank Number   | Amount  | Status     | Coach   | Quantity | Seat(s)                \n");
                printf("===============================================================================================================================================================================\n");
                printf("| %-10s | %-9s |%-8s | %-13s | %-13s |", tempBooking.bookingID, tempBooking.memberID, tempBooking.trainID,
                    tempBooking.bookingDate, tempBooking.departureDate);


                printf(" %-20s | %-13s | %-7.2f | %-10s | %-7s | %-8d |",
                    tempBooking.bankName, tempBooking.bankNumber, tempBooking.amount, tempBooking.status,
                    tempBooking.coach, tempBooking.quantity);


                for (int i = 0; i < tempBooking.quantity; i++) {
                    printf("%-3s    ", tempBooking.seatNumber[i]);
                }
                printf("\n\n");
            }
        }
        printf("===============================================================================================================================================================================\n");

        if (!found) {
            printRed("\nNo bookings found for the specified train ID.\n");
        }

        break;
    }
    default:
        printRed("\nInvalid choice.\n");
        break;
    }

    fclose(ticket);
    printCyan("Press Enter To Continue...");
    getchar();
    getchar();
}



int bookingMenu(const char* memberID) {

    int choice;

    do {

        printf(" _______ _____ _____ _  ________ _______   ____   ____   ____  _  _______ _   _  _____   __  __ ______ _   _ _    _ \n");
        printf("|__   __|_   _/ ____| |/ |  ____|__   __| |  _ \\ / __ \\ / __ \\| |/ |_   _| \\ | |/ ____| |  \\/  |  ____| \\ | | |  | |\n");
        printf("   | |    | || |    | ' /| |__     | |    | |_) | |  | | |  | | ' /  | | |  \\| | |  __  | \\  / | |__  |  \\| | |  | |\n");
        printf("   | |    | || |    |  < |  __|    | |    |  _ <| |  | | |  | |  <   | | | . ` | | |_ | | |\\/| |  __| | . ` | |  | |\n");
        printf("   | |   _| || |____| . \\| |____   | |    | |_) | |__| | |__| | . \\ _| |_| |\\  | |__| | | |  | | |____| |\\  | |__| |\n");
        printf("   |_|  |_____|\\_____|_|\\_|______|  |_|    |____/ \\____/ \\____/|_|\\_|_____|_| \\_|\\_____| |_|  |_|______|_| \\_|\\____/ \n");
        printf("                                                                                                                        \n");
        printf("                                                                                                                        \n");




        printf("                  __________________________\n");
        printf("                 |1. Add Booking            |\n");
        printf("                 |2. Search Booking         |\n");
        printf("                 |3. Modify Booking         |\n");
        printf("                 |4. Display All Bookings   |\n");
        printf("                 |5. Payment                |\n");
        printf("                 |6. Cancel Booking         |\n");
        printf("                 |7. Exit                   |\n");
        printf("                 ---------------------------\n");
        printf("                   Enter your choice : ");
        scanf("%d", &choice);
        system("cls");

        switch (choice) {
        case 1:
            addBooking(memberID);
            system("cls");
            break;
        case 2:
            searchBooking(memberID);
            system("cls");
            break;
        case 3:
            modifyBooking(memberID);
            system("cls");
            break;
        case 4:
            displayBooking(memberID);
            system("cls");
            break;
        case 5:
            payPending(memberID);
            system("cls");
            break;
        case 6:

            cancelBooking(memberID);
            system("cls");
            break;
        case 7:
            system("cls");
            break;
        default:
            printRed("\nInvalid Choice,Please Enter Again!");
        }
    } while (choice != 7);

}

void confirmRegistration() {
    char choice;
    printf("Registration successful! Do you want to go back to the main menu to login? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        loginUser();
    }
    else {
        printf("Exiting...\n");
        exit(0);
    }
}

void registerUser() {
    FILE* file = fopen("scheduleuser.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    User newUser;

    do {
        printf("Enter userID (adminxxx format): ");
        scanf("%s", newUser.userID);


        if (strncmp(newUser.userID, "admin", 5) != 0) {
            printf("UserID must start with 'admin'. Please try again.\n");
            continue;
        }

        FILE* checkFile = fopen("scheduleuser.txt", "r");
        if (checkFile == NULL) {
            printf("Error opening file for checking existing IDs.\n");
            fclose(file);
            return;
        }

        char existingUserID[50];
        while (fscanf(checkFile, "%s", existingUserID) != EOF) {
            if (strcmp(existingUserID, newUser.userID) == 0) {
                printf("UserID already exists. Please choose a different one.\n");
                fclose(checkFile);
                registerUser();
            }
        }

        fclose(checkFile);
        break;

    } while (1);

    printf("Enter password (integer only): ");
    scanf("%d", &newUser.password);

    printf("Enter phone number: ");
    scanf("%d", &newUser.phoneNumber);

    fprintf(file, "%s %d %d\n", newUser.userID, newUser.password, newUser.phoneNumber);
    fclose(file);

    confirmRegistration();
}



void loginUser() {
    char userID[50];
    int password;

    printf("Enter userID: ");
    scanf("%s", userID);

    printf("Enter password: ");
    scanf("%d", &password);

    FILE* file = fopen("scheduleuser.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char fileUserID[50];
    int filePassword, filePhoneNumber;

    while (fscanf(file, "%s %d %d", fileUserID, &filePassword, &filePhoneNumber) != EOF) {
        if (strcmp(fileUserID, userID) == 0 && filePassword == password) {
            printf("Login successful!\n");
            fclose(file);
            trainMain();
            return;
        }
    }

    fclose(file);
    printf("Invalid userID or password. Please try again.\n");
}


void forgotPassword() {
    char userID[50];
    int phoneNumber;

    printf("Enter userID: ");
    scanf("%s", userID);

    printf("Enter phone number: ");
    scanf("%d", &phoneNumber);

    FILE* file = fopen("scheduleuser.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char fileUserID[50];
    int filePassword, filePhoneNumber;

    while (fscanf(file, "%s %d %d", fileUserID, &filePassword, &filePhoneNumber) != EOF) {
        if (strcmp(fileUserID, userID) == 0 && filePhoneNumber == phoneNumber) {
            printf("Your password is: %d\n", filePassword);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("User not found or phone number does not match. Please try again.\n");
}

int tmain() {
    int choice;

    while (1) {
        printf("\n=============== Main Menu ===============\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Forgot Password\n");
        printf("0. Exit\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            forgotPassword();
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}




void trainMain() {
    int choice;
    printf("+===================================================================================================================================================================+\n");
    printf("|                                                                                                                                                                   |\n");
    printf("|                    __________      __________     ____       ____     _________      ________      ___       ___     ___             _________                    |\n");
    printf("|                   |          |    |          |   |    |     |    |   |         |    |         |   |   |     |   |   |   |           |         |                   |\n");
    printf("|                   |    ______|    |    ______|   |    |_____|    |   |     ____|    |         |   |   |     |   |   |   |           |     ____|                   |\n");
    printf("|                   |   |______     |   |          |               |   |    |____     |    _    |   |   |     |   |   |   |           |    |____                    |\n");
    printf("|                   |____      |    |   |          |               |   |         |    |   |_|   |   |   |     |   |   |   |           |         |                   |\n");
    printf("|                        |     |    |   |______    |     _____     |   |     ____|    |         |   |   |_____|   |   |   |_______    |     ____|                   |\n");
    printf("|                   _____|     |    |          |   |    |     |    |   |    |____     |         |   |             |   |           |   |    |____                    |\n");
    printf("|                  |___________|    |__________|   |____|     |____|   |_________|    |________ |   | ___________ |   |___________|   |_________|                   |\n");
    printf("|                                                                                                                                                                   |\n");
    printf("|                                                                                                                                                                   |\n");
    printf("+===================================================================================================================================================================+\n\n");
    printf("     Train Schedule Module     \n");
    printf("===============================\n");
    printf("1. Add New Train Schedule\n");
    printf("2. Search Train Schedule\n");
    printf("3. View All Train Schedule\n");
    printf("4. Modify stock\n");
    printf("5. Delete Train Schedule\n");
    printf("6. Filter Train\n");
    printf("0. Exit\n");
    printf("==================================\n");
    printf("Enter your Choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        addTrain();
        break;
    case 2:
        searchTrain();
        break;
    case 3:
        viewTrainSchedule();
        break;
    case 4:
        modifyTrain();
        break;
    case 5:
        deleteTrain();
        break;
    case 6:
        filterTrain();
        break;
    case 0:
        printf("You have exited the program!\n");
        break;
    default:
        printf("\n!!Invalid choice!!\n\n");
        printf("Please enter number(1-6) again,\nOr enter 0 to exit the program.\n\n");
        return 1;
    }

    return 0;
}

void clearBuffer() {
    while (getchar() != '\n');
}

void addTrain() {
    FILE* fp;
    char choice = 'y';

    fp = fopen("schedule.txt", "a");
    if (fp == NULL) {
        printf("Unable to open FILE.\n");
        exit(1);
    }

    while (choice == 'y' || choice == 'Y') {
        Train newTrain;

        printf("\nEnter Train details\n");
        printf("---------------------\n");

        printf("Train ID (max 19 characters): ");
        scanf("%19s", newTrain.id);
        clearBuffer();


        FILE* checkFile = fopen("schedule.txt", "r");
        if (checkFile == NULL) {
            printf("Error opening file for checking existing IDs.\n");
            fclose(fp);
            return;
        }

        char existingTrainID[20];
        while (fscanf(checkFile, "%19[^|]|%*[^\n]\n", existingTrainID) != EOF) {
            if (strcmp(existingTrainID, newTrain.id) == 0) {
                printf("Train ID already exists. Please choose a different one.\n");
                fclose(checkFile);
                addTrain();
            }
        }

        fclose(checkFile);

        printf("Departure station (max 99 characters): ");
        fgets(newTrain.departureStation, sizeof(newTrain.departureStation), stdin);
        strtok(newTrain.departureStation, "\n");

        printf("Arrival station (max 99 characters): ");
        fgets(newTrain.arriveStation, sizeof(newTrain.arriveStation), stdin);
        strtok(newTrain.arriveStation, "\n");

        printf("Departure time (HH:MM AM/PM): ");
        scanf("%19s", newTrain.departureTime);
        clearBuffer();

        printf("Arrival time (HH:MM AM/PM): ");
        scanf("%19s", newTrain.arrivalTime);
        clearBuffer();

        printf("Date (MMDD): ");
        scanf("%19s", newTrain.date);
        clearBuffer();

        do {
            printf("Available seats (50 or 100): ");
            scanf("%d", &newTrain.availableSeats);
            clearBuffer();

            if (newTrain.availableSeats != 50 && newTrain.availableSeats != 100) {
                printf("Please enter either 50 or 100 for available seats.\n");
            }
        } while (newTrain.availableSeats != 50 && newTrain.availableSeats != 100);

        printf("Economy class price: ");
        scanf("%lf", &newTrain.economyPrice);
        clearBuffer();

        printf("First class price: ");
        scanf("%lf", &newTrain.firstClassPrice);
        clearBuffer();


        fprintf(fp, "%s|%s|%s|%s|%s|%s|%d|%.2lf|%.2lf\n",
            newTrain.id, newTrain.departureStation, newTrain.arriveStation,
            newTrain.departureTime, newTrain.arrivalTime, newTrain.date,
            newTrain.availableSeats, newTrain.economyPrice, newTrain.firstClassPrice);

        printf("Record added successfully!\n");

        printf("Do you want to add another Train record? (y/n): ");
        scanf(" %c", &choice);
        clearBuffer();
    }

    fclose(fp);

    char response;
    printf("\nDo you want to go back to the main menu? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        system("cls");
        trainMain();
    }
    else if (response == 'n' || response == 'N') {
        printf("Exiting the program...\n");
    }
    else {
        printf("Invalid input! Exiting the program...\n");
    }
}






void viewTrainSchedule() {
    FILE* fp;
    fp = fopen("schedule.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    Train train;
    int recordsFound = 0;


    if (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%lf|%lf\n", train.id, train.departureStation, train.arriveStation, train.departureTime, train.arrivalTime, train.date, &train.availableSeats, &train.economyPrice, &train.firstClassPrice) == EOF) {
        printf("No records found.\n");
    }
    else {

        printf("\n\t\t\t\t\t           <<<TRAIN SCHEDULE>>>\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("ID    \tDeparture Station  Arrival Station  Departure Time    Arrival Time\tDate\tAvailable Seats\tEconomy Price\tFirst Class Price\n");
        printf("=======\t================= ===============  ===============   =============\t=======\t===============\t==============\t================\n");


        do {
            printf("%-7s %-20s %-20s %-15s %-15s %-10s %-15d %-15.2lf %-15.2lf\n", train.id, train.departureStation, train.arriveStation, train.departureTime, train.arrivalTime, train.date, train.availableSeats, train.economyPrice, train.firstClassPrice);
            recordsFound = 1;
        } while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%lf|%lf\n", train.id, train.departureStation, train.arriveStation, train.departureTime, train.arrivalTime, train.date, &train.availableSeats, &train.economyPrice, &train.firstClassPrice) != EOF);
    }

    printf("\n");

    fclose(fp);

    char response;
    printf("Do you want to go back to the main menu? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        system("cls");
        trainMain();
    }
    else if (response == 'n' || response == 'N') {
        printf("Exiting the program...\n");
    }
    else {
        printf("Invalid input! Exiting the program...\n");
    }
}



void searchTrain() {
    char searchID[20];
    FILE* fp;
    fp = fopen("schedule.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file..\n");
        return;
    }

    printf("Enter the train ID to search: ");
    scanf("%19s", searchID);

    Train train;
    int found = 0;
    while (fscanf(fp, "%19[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%lf|%lf\n", train.id, train.departureStation, train.arriveStation, train.departureTime, train.arrivalTime, train.date, &train.availableSeats, &train.economyPrice, &train.firstClassPrice) != EOF) {
        if (strcmp(train.id, searchID) == 0) {
            found = 1;
            printf("\nTrain found:\n");
            printf("ID: %s\n", train.id);
            printf("Departure Station: %s\n", train.departureStation);
            printf("Arrival Station: %s\n", train.arriveStation);
            printf("Departure Time: %s\n", train.departureTime);
            printf("Arrival Time: %s\n", train.arrivalTime);
            printf("Date: %s\n", train.date);
            printf("Available Seats: %d\n", train.availableSeats);
            printf("Economy Class Price: %.2lf\n", train.economyPrice);
            printf("First Class Price: %.2lf\n", train.firstClassPrice);
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Train not found!\n");
    }

    char response;
    printf("Do you want to go back to the main menu? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        system("cls");
        trainMain();
    }
    else if (response == 'n' || response == 'N') {
        printf("Exiting the program...\n");
    }
    else {
        printf("Invalid input! Exiting the program...\n");
    }
}



void modifyTrain() {
    FILE* fp = fopen("schedule.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file..\n");
        return;
    }

    Train trainSchedule[100];
    int trainCount = 0;
    while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%lf|%lf\n", trainSchedule[trainCount].id, trainSchedule[trainCount].departureStation, trainSchedule[trainCount].arriveStation, trainSchedule[trainCount].departureTime, trainSchedule[trainCount].arrivalTime, trainSchedule[trainCount].date, &trainSchedule[trainCount].availableSeats, &trainSchedule[trainCount].economyPrice, &trainSchedule[trainCount].firstClassPrice) != EOF) {
        trainCount++;
    }

    fclose(fp);

    char searchID[100];
    printf("Enter the train ID to modify: ");
    scanf("%99s", searchID);

    int index = -1;
    for (int i = 0; i < trainCount; i++) {
        if (strcmp(trainSchedule[i].id, searchID) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Train not found\n");
        return;
    }

    Train newTrain = trainSchedule[index];

    printf("\nCurrent train details:\n");
    printf("ID: %s\n", newTrain.id);
    printf("Departure Station: %s\n", newTrain.departureStation);
    printf("Arrival Station: %s\n", newTrain.arriveStation);
    printf("Departure Time: %s\n", newTrain.departureTime);
    printf("Arrival Time: %s\n", newTrain.arrivalTime);
    printf("Date: %s\n", newTrain.date);
    printf("Available Seats: %d\n", newTrain.availableSeats);
    printf("Economy Price: %.2lf\n", newTrain.economyPrice);
    printf("First Class Price: %.2lf\n", newTrain.firstClassPrice);
    printf("\nEnter new details:\n");

    char inputDepartureTime[20];
    printf("Enter new departure time (HH:MM AM/PM) (enter 0 to keep current value): ");
    scanf("%19s", inputDepartureTime);
    if (strcmp(inputDepartureTime, "0") != 0) {
        strcpy(newTrain.departureTime, inputDepartureTime);
    }

    char inputArrivalTime[20];
    printf("Enter new arrival time (HH:MM AM/PM) (enter 0 to keep current value): ");
    scanf("%19s", inputArrivalTime);
    if (strcmp(inputArrivalTime, "0") != 0) {
        strcpy(newTrain.arrivalTime, inputArrivalTime);
    }

    char inputDate[20];
    printf("Enter new date (MM-DD) (enter 0 to keep current value): ");
    scanf("%19s", inputDate);
    if (strcmp(inputDate, "0") != 0) {
        strcpy(newTrain.date, inputDate);
    }

    int inputAvailableSeats;
    printf("Enter new available seats (enter 0 to keep current value): ");
    scanf("%d", &inputAvailableSeats);
    if (inputAvailableSeats != 0) {
        newTrain.availableSeats = inputAvailableSeats;
    }

    double inputEconomyPrice;
    printf("Enter new economy class price (enter 0 to keep current value): ");
    scanf("%lf", &inputEconomyPrice);
    if (inputEconomyPrice != 0) {
        newTrain.economyPrice = inputEconomyPrice;
    }

    double inputFirstClassPrice;
    printf("Enter new first class price (enter 0 to keep current value): ");
    scanf("%lf", &inputFirstClassPrice);
    if (inputFirstClassPrice != 0) {
        newTrain.firstClassPrice = inputFirstClassPrice;
    }



    trainSchedule[index] = newTrain;

    fp = fopen("schedule.txt", "w");
    if (fp == NULL) {
        printf("Unable to open file..\n");
        return;
    }

    for (int i = 0; i < trainCount; i++) {
        fprintf(fp, "%s|%s|%s|%s|%s|%s|%d|%.2lf|%.2lf\n",
            trainSchedule[i].id, trainSchedule[i].departureStation, trainSchedule[i].arriveStation,
            trainSchedule[i].departureTime, trainSchedule[i].arrivalTime, trainSchedule[i].date,
            trainSchedule[i].availableSeats, trainSchedule[i].economyPrice, trainSchedule[i].firstClassPrice);
    }

    fclose(fp);
    printf("\nTrain details modified successfully!\n");

    char response;
    printf("Do you want to go back to the main menu? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        system("cls");
        trainMain();
    }
    else if (response == 'n' || response == 'N') {
        printf("Exiting the program...\n");
    }
    else {
        printf("Invalid input! Exiting the program...\n");
    }
}




void deleteTrain() {
    char searchID[20];
    FILE* fp;
    FILE* tempFile;
    fp = fopen("schedule.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file..\n");
        return;
    }
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Unable to open file..\n");
        fclose(fp);
        return;
    }

    printf("Enter the train ID to delete: ");
    scanf("%19s", searchID);

    Train train;
    int found = 0;
    while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%lf|%lf\n", train.id, train.departureStation, train.arriveStation, train.departureTime, train.arrivalTime, train.date, &train.availableSeats, &train.economyPrice, &train.firstClassPrice) != EOF) {

        if (strcmp(train.id, searchID) != 0) {
            fprintf(tempFile, "%s|%s|%s|%s|%s|%s|%d|%.2lf|%.2lf\n",
                train.id, train.departureStation, train.arriveStation,
                train.departureTime, train.arrivalTime, train.date,
                train.availableSeats, train.economyPrice, train.firstClassPrice);
        }
        else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(tempFile);

    remove("schedule.txt");
    rename("temp.txt", "schedule.txt");

    if (found) {
        printf("Train details deleted successfully!\n");
    }
    else {
        printf("Train not found!\n");
    }

    char response;
    printf("Do you want to go back to the main menu? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        system("cls");
        trainMain();
    }
    else if (response == 'n' || response == 'N') {
        printf("Exiting the program...\n");
    }
    else {
        printf("Invalid input! Exiting the program...\n");
    }
}


void filterTrain() {
    FILE* fp = fopen("schedule.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file..\n");
        return;
    }

    Train trainSchedule;
    printf("Enter filter criteria:\n");
    printf("Departure Station: ");
    char filterDepartureStation[100];
    scanf("%99s", filterDepartureStation);

    printf("Arrival Station: ");
    char filterArrivalStation[100];
    scanf("%99s", filterArrivalStation);

    printf("\nFiltered Train Schedule:\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| Train ID | Departure Station | Arrival Station | Departure Time | Arrival Time | Date     |\n");
    printf("----------------------------------------------------------------------------------------------\n");
    while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%lf|%lf\n", trainSchedule.id, trainSchedule.departureStation, trainSchedule.arriveStation, trainSchedule.departureTime, trainSchedule.arrivalTime, trainSchedule.date, &trainSchedule.availableSeats, &trainSchedule.economyPrice, &trainSchedule.firstClassPrice) != EOF) {
        if (strcmp(trainSchedule.departureStation, filterDepartureStation) == 0 &&
            strcmp(trainSchedule.arriveStation, filterArrivalStation) == 0) {
            printf("| %-8s| %-17s| %-15s| %-14s| %-13s| %-8s|\n",
                trainSchedule.id, trainSchedule.departureStation, trainSchedule.arriveStation,
                trainSchedule.departureTime, trainSchedule.arrivalTime, trainSchedule.date);
        }
    }

    fclose(fp);

    char response;
    printf("\nDo you want to go back to the main menu? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        system("cls");
        trainMain();
    }
    else if (response == 'n' || response == 'N') {
        printf("Exiting the program...\n");
    }
    else {
        printf("Invalid input! Exiting the program...\n");
    }
}

void printred(const char* text) {
    printf("\033[1;31m%s\033[0m", text);
}

void printcyan(const char* text) {
    printf("\033[1;36m%s\033[0m", text);
}

void printyellow(const char* text) {
    printf("\033[1;33m%s\033[0m", text);
}

void printgreen(const char* text) {
    printf("\033[1;32m%s\033[0m", text);
}

void registermember() {
    Member member;
    FILE* registermember;
    char uppercase[20];
    registermember = fopen("member_information.dat", "ab");

    if (!registermember) {
        printf("Error opening file.\n");
        exit(-1);
    }

    printf("----------------------------\n");
    printcyan("    member registeration    \n");
    printf("----------------------------\n");

    do {
        printf("Enter your member id(M2305XXX):");
        scanf("%s", member.memberID);
        rewind(stdin);


        if (strlen(member.memberID) != 8 || strncmp(member.memberID, "M", 1) != 0) {
            printred("Invalid member format.\n");
        }
    } while (strlen(member.memberID) != 8 || strncmp(member.memberID, "M", 1) != 0);

    do {
        printf("Enter your name (20 max): ");
        scanf("%s", member.name);
        rewind(stdin);

        if (strlen(member.name) > 20) {
            printred("Name too long,Enter a shorter name\n");
        }
    } while (strlen(member.name) > 20);

    do {
        printf("Enter your password: ");
        scanf("%s", member.password);
        rewind(stdin);

        if (strlen(member.password) < 5) {
            printred("Password Too Weak, please use atleast 5 character\n");
        }

        if (strlen(member.password) > 20) {
            printred("Password Too Long,please enter a shorter password\n");
        }

    } while (strlen(member.password) < 5 || strlen(member.password) > 20);;

    do {
        printf("Enter your recovery password(3 max):");
        scanf("%s", member.password_recovery);
        rewind(stdin);
        if (strlen(member.password_recovery) > 3) {
            printred("Password too long,please enter a shorter password\n");
        }
    } while (strlen(member.password_recovery) > 3);

    do {
        printf("Enter your IC(XXXXXX-XX-XXXX):");
        scanf("%[^-]-%[^-]-%d", member.memberIC.birth, member.memberIC.birthplace, &member.memberIC.birthnum);
        rewind(stdin);
        if (strlen(member.memberIC.birth) != 6 || strlen(member.memberIC.birthplace) != 2 || member.memberIC.birthnum < 0 || member.memberIC.birthnum > 9999) {
            printred("Invalid format\n");
        }
    } while (strlen(member.memberIC.birth) != 6 || strlen(member.memberIC.birthplace) != 2 || member.memberIC.birthnum < 0 || member.memberIC.birthnum > 9999);

    if (member.memberIC.birthnum % 2 == 0)
    {
        member.gender = 'F';
        printf("Gender:F\n");
    }
    else {
        member.gender = 'M';
        printf("Gender:M\n");
    }

    do {
        printf("Enter your phone num(01XXXXXXXX):");
        scanf("%s", member.phonenum);
        rewind(stdin);
        if (strlen(member.phonenum) != 10) {
            printred("invalid phone num\n");
        }
    } while (strlen(member.phonenum) != 10);

    printgreen("Registration successful\n");
    printf("Enter any key to continue...");
    printf("\n");

    fwrite(&member, sizeof(Member), 1, registermember);
    fclose(registermember);
    system("cls");
    membermenu();
}

void loginmember() {
    FILE* memberlogin;
    char memberID[15];
    char memberpass[20];
    int memberchoice;
    Member member;
    int found = 0;

    memberlogin = fopen("member_information.dat", "rb");

    if (!memberlogin) {
        printf("Error opening file\n");
        exit(-1);
    }

    do {
        printf("Enter your member id (M2305XXX): ");
        scanf("%s", memberID);
        rewind(stdin);

        for (int i = 0; memberID[i]; i++) {
            memberID[i] = toupper(memberID[i]);
        }

        if (strlen(memberID) != 8 || strncmp(memberID, "M", 1) != 0) {
            printred("Invalid member format.\n");
        }
    } while (strlen(memberID) != 8 || strncmp(memberID, "M", 1) != 0);

    while (fread(&member, sizeof(Member), 1, memberlogin) != 0) {
        if (strcmp(memberID, member.memberID) == 0) {
            found = 1;
            printgreen("Member ID found\n");
            printf("Enter your password: ");
            scanf("%s", memberpass);
            rewind(stdin);

            if (strcmp(memberpass, member.password) == 0) {
                printgreen("Login successful\n");
                fclose(memberlogin);
                membermenu();
                return;
            }
            else {
                printred("Invalid password\n");
                printyellow("Enter 1 to try again\n");
                printyellow("Enter 2 to recover password\n");
                printyellow("Enter your choice: ");
                scanf("%d", &memberchoice);
                rewind(stdin);

                switch (memberchoice) {
                case 1:
                    fclose(memberlogin);
                    system("cls");
                    loginmember();
                    break;
                case 2:
                    fclose(memberlogin);
                    system("cls");
                    if (recoverpassword(memberID)) {
                        return;
                    }
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
                }
            }
        }
    }

    fclose(memberlogin);

    if (!found) {
        printf("Member ID not found\n");
    }

}

int recoverpassword(const char* memberID) {
    FILE* recover;
    FILE* temp;
    char recoverypass[20];
    Member member;
    int found = 0;

    recover = fopen("member_information.dat", "rb");
    temp = fopen("membertemp.dat", "wb");

    if (!recover || !temp) {
        printf("Error opening files\n");
        exit(-1);
    }

    printf("Enter your recovery password: ");
    scanf("%s", recoverypass);
    rewind(stdin);

    while (fread(&member, sizeof(Member), 1, recover) != 0) {
        if (strcmp(recoverypass, member.password_recovery) == 0 && strcmp(memberID, member.memberID) == 0) {
            found = 1;
            printf("Password recovery successful\n");
            printf("Enter your new password: ");
            scanf("%s", member.password);
            rewind(stdin);
            fwrite(&member, sizeof(Member), 1, temp);
            membermenu();
        }
        else {
            fwrite(&member, sizeof(Member), 1, temp);
        }
    }

    fclose(recover);
    fclose(temp);

    if (!found) {
        printred("Invalid recovery password or member ID\n");
        remove("membertemp.dat");
        loginmember();
        return 0;
    }

    remove("member_information.dat");
    rename("membertemp.dat", "member_information.dat");
    return 1;

}

void loginmenu() {

    int memberchoice;
    printf("----------------------------\n");
    printcyan("         Login Menu         \n");
    printf("----------------------------\n");

    printf("1.Register\n");
    printf("2.Login\n");
    printf("3.Exit\n");
    printf("select one of the above:");
    rewind(stdin);
    scanf("%d", &memberchoice);

    switch (memberchoice) {
    case 1:
        system("cls");
        registermember();
        break;
    case 2:
        system("cls");
        loginmember();
        break;
    case 3:
        break;
    default:
        break;
    }


}

void membermenu() {
    int memberchoice;

    printf("----------------------------\n");
    printcyan("        Member Menu         \n");
    printf("----------------------------\n");

    printf("1.Search\n");
    printf("2.Change Information\n");
    printf("3.Sign out\n");

    do {
        printf("select one of the above:");
        rewind(stdin);
        scanf("%d", &memberchoice);

        if (memberchoice < 1 || memberchoice > 3) {
            printred("Invalid selection\n");
        }
    } while (memberchoice < 1 || memberchoice > 3);

    switch (memberchoice) {

    case 1:
        system("cls");
        searchmember();
        break;
    case 2:
        system("cls");
        modifymember();
        break;
    case 3:
        system("cls");
        loginmenu();
        break;
    default:
        printred("Invalid selection\n");
        membermenu();
        break;
    }
}

void searchmember() {
    char search[15];
    Member member;

    FILE* searchmembers = fopen("member_information.dat", "rb");

    if (!searchmembers) {
        printf("Error opening file\n");
        exit(-1);
    }

    printf("Enter the member ID to search: ");
    scanf("%s", search);

    while (fread(&member, sizeof(Member), 1, searchmembers) != 0) {
        if (strcmp(search, member.memberID) == 0) {
            displaymember(search);
            fclose(searchmembers);
            return;
        }
    }
    printf("%s does not exist\n", search);
    fclose(searchmembers);

    char choice;
    printf("Do you want to search again? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        searchmember();
    }
    else {
        printf("Exiting search process.\n");
    }
}

void modifymember() {
    Member member;
    int memberchoice;
    char oldpass[20];

    FILE* changeinfo = fopen("membertemp.dat", "wb");
    FILE* readinfo = fopen("member_information.dat", "rb");

    printf("------------------\n");
    printcyan("Change Information\n");
    printf("------------------\n");

    printf("1.Change Password\n");
    printf("2.Change Contact\n");

    do {
        printf("What do you want to change?: ");
        scanf("%d", &memberchoice);
    } while (memberchoice < 1 || memberchoice > 2);

    switch (memberchoice) {
    case 1:
        printgreen("Change password selected\n");
        printf("Enter your current password: ");
        scanf("%s", oldpass);

        int passwordFound = 0;

        while (fread(&member, sizeof(Member), 1, readinfo) != 0) {
            if (strcmp(oldpass, member.password) == 0) {
                printf("Enter your new password: ");
                scanf("%s", member.password);
                fwrite(&member, sizeof(Member), 1, changeinfo);
                printf("Password updated successfully.\n");
                passwordFound = 1;
            }
            else {
                fwrite(&member, sizeof(Member), 1, changeinfo);
            }
        }

        if (!passwordFound) {
            printf("Incorrect password.\n");
        }
        break;
    case 2:
        printgreen("Change contact selected\n");
        printf("Enter your new contact (01XXXXXXXX): ");
        scanf("%s", member.phonenum);

        while (fread(&member, sizeof(Member), 1, readinfo) != 0) {
            fwrite(&member, sizeof(Member), 1, changeinfo);
        }
        break;
    default:
        break;
    }

    fclose(changeinfo);
    fclose(readinfo);

    remove("member_information.dat");
    rename("membertemp.dat", "member_information.dat");
}

void displaymember(const char* memberID) {
    Member member;
    struct Booking book;
    int memberchoice;

    FILE* displaymember = fopen("member_information.dat", "rb");
    FILE* displaymember2 = fopen("bookings.dat", "rb");

    printf("-----------------------\n");
    printcyan("   Member Information  \n");
    printf("-----------------------\n");

    while (fread(&member, sizeof(Member), 1, displaymember) != 0) {
        if (strcmp(memberID, member.memberID) == 0) {
            printyellow("------------------------------------------\n\n");

            printf("ID: %s \n", member.memberID);
            printf("name: %s \n", member.name);
            printf("password: ********* \n");
            printf("gender:%c \n", member.gender);
            printf("IC:%s-%s-%d \n", member.memberIC.birth, member.memberIC.birthplace, member.memberIC.birthnum);
            printf("Contact:%s \n\n", member.phonenum);

            printyellow("------------------------------------------\n\n");
            break;
        }
    }

    while (fread(&book, sizeof(struct Booking), 1, displaymember2) != 0) {
        printf("bookingID:%s \n\n", book.bookingID);
    }

    printf("1.Search for another\n");
    printf("2.Travel history\n");
    printf("3.Back to menu\n");

    do {
        printf("Enter your choice:");
        scanf("%d", &memberchoice);
    } while (memberchoice < 1 || memberchoice > 3);

    switch (memberchoice) {
    case 1:
        searchmember();
        break;
    case 2:
        travelhistory();
        break;
    case 3:
        membermenu();
        break;
    }
    fclose(displaymember);
    fclose(displaymember2);
}

void travelhistory() {
    FILE* ticket;
    ticket = fopen("bookings.dat", "rb");
    if (ticket == NULL) {
        printf("Unable to open the file.\n");
        exit(-1);
    }

    struct Booking tempBooking;

    printf("Bookings:\n");
    printf("==========================================================================================================================\n");
    printf("| Booking ID | Member ID  | Booking Date  | Departure Date| Coach | Quantity | Amount |    Seats    |\n");
    printf("==========================================================================================================================\n");
    while (fread(&tempBooking, sizeof(struct Booking), 1, ticket) == 1) {
        printf("| %-10s | %-9s | %-13s | %-13s |", tempBooking.bookingID, tempBooking.memberID, tempBooking.bookingDate, tempBooking.departureDate);


        printf("%-5s | %-8d | %-7.2f |",
            tempBooking.coach, tempBooking.quantity,
            tempBooking.amount);

        printf(" ");
        for (int i = 0; i < tempBooking.quantity; i++) {
            printf("%-3s    ", tempBooking.seatNumber[i]);
        }

    }
    printf("|\n");
    printf("==========================================================================================================================\n");

    membermenu();
    fclose(ticket);
}






void staffManage() {
    int choice;
    do {
        printf("\t\t\t _____                                                             _____ \n");
        printf("\t\t\t( ___ )-----------------------------------------------------------( ___ )\n");
        printf("\t\t\t |   |                                                             |   | \n");
        printf("\t\t\t |   | _______ _______ _______ _______ _______                     |   | \n");
        printf("\t\t\t |   | |______    |    |_____| |______ |______                     |   | \n");
        printf("\t\t\t |   | ______|    |    |     | |       |                           |   | \n");
        printf("\t\t\t |   |                                                             |   | \n");
        printf("\t\t\t |   | _______ _______ __   _ _     _      ______  _______  ______ |   | \n");
        printf("\t\t\t |   | |  |  | |______ | \\  | |     |      |_____] |_____| |_____/ |   | \n");
        printf("\t\t\t |   | |  |  | |______ |  \\_| |_____|      |_____] |     | |    \\_ |   | \n");
        printf("\t\t\t |___|                                                             |___| \n");
        printf("\t\t\t(_____)-----------------------------------------------------------(_____) \n\n\n");
        printf("\t\t\t\t1.Register\n");
        printf("\t\t\t\t2.Login\n");
        printf("\t\t\t\t3.Password Recovery (IF YOU FORGET YOUR PASSWORD)\n");
        printf("\t\t\t\t0.Exit\n");
        printf("\t\t\t\tEnter your choice > ");
        scanf("%d", &choice);
        rewind(stdin);

        switch (choice) {
        case 1:
            system("cls");
            staffRegister();
            break;
        case 2:
            system("cls");
            staffLogin();
            break;
        case 3:
            system("cls");
            passwordRecovery();
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 0);
}

void staffRegister() {
    FILE* fptr = fopen("staff_information.txt", "r");


    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(-1);
    }

    staff newStaff;
    int exitInput;
    char regStaffID[7];
    int atIndex = -1;
    int isValid = 0;

    printf("Staff Register\n");
    printf("-----------------\n");

    do {
        printf("Enter staff ID in (STFXXX): ");
        scanf("%s", regStaffID);
        rewind(stdin);
        if (strlen(regStaffID) != 6 || strncmp(regStaffID, "STF", 3) != 0) {
            red();
            printf("Invalid staff ID format. Please enter in STFXXX format.\n");
            black();
        }
        else {
            rewind(fptr);
            while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", newStaff.staffID, newStaff.staffName, newStaff.password, newStaff.passwordRecovery, newStaff.email, newStaff.position, newStaff.ic, newStaff.religion, &newStaff.phoneNumber, &newStaff.age) != EOF) {
                if (strcmp(newStaff.staffID, regStaffID) == 0) {
                    red();
                    printf("\nStaff ID has been registered.\n");
                    printf("Please enter again.\n\n");
                    black();
                    break;
                }
            }
        }
    } while (strlen(regStaffID) != 6 || strncmp(regStaffID, "STF", 3) != 0 || strcmp(newStaff.staffID, regStaffID) == 0);
    fclose(fptr);

    printf("Enter Name: ");
    scanf("%[^\n]", newStaff.staffName);
    rewind(stdin);

    printf("Enter password: ");
    scanf("%s", newStaff.password);
    rewind(stdin);

    printf("Enter password recovery: ");
    scanf("%s", newStaff.passwordRecovery);
    rewind(stdin);

    do {
        printf("Enter email (must in @gmail.com): ");
        scanf("%s", newStaff.email);
        rewind(stdin);

        atIndex = -1;
        int len = strlen(newStaff.email);

        for (int i = 0; i < len; i++) {
            if (newStaff.email[i] == '@') {
                atIndex = i;
                break;
            }
        }

        if (atIndex == -1 || strcmp(newStaff.email + atIndex + 1, "gmail.com") != 0) {
            red();
            printf("Invalid email format\n");
            black();
        }
    } while (atIndex == -1 || strcmp(newStaff.email + atIndex + 1, "gmail.com") != 0);

    do {
        printf("Enter position (ADM for ADMIN, STF for STAFF): ");
        scanf("%s", newStaff.position);
        rewind(stdin);
        if (strcmp(newStaff.position, "ADM") != 0 && strcmp(newStaff.position, "STF") != 0) {
            red();
            printf("Please enter a valid position!\n");
            black();
        }
    } while (strcmp(newStaff.position, "ADM") != 0 && strcmp(newStaff.position, "STF") != 0);

    do {
        printf("Enter IC in (YYMMDD-PB-###G): ");
        scanf("%[^\n]", newStaff.ic);
        rewind(stdin);
        if (strlen(newStaff.ic) != 14) {
            red();
            printf("Invalid IC format. Please enter in YYMMDD-PB-###G format.\n");
            black();
        }

        if (newStaff.ic[6] != '-' || newStaff.ic[9] != '-') {
            red();
            printf("Invalid IC format. Please enter in YYMMDD-PB-###G format.\n");
            black();
        }
    } while (strlen(newStaff.ic) != 14 || newStaff.ic[6] != '-' || newStaff.ic[9] != '-');

    do {
        printf("Enter religion (Islam/Buddhism/Christianity/Hinduism/None): ");
        scanf("%s", newStaff.religion);
        rewind(stdin);

        for (int i = 0; newStaff.religion[i]; i++) {
            newStaff.religion[i] = tolower(newStaff.religion[i]);
        }

        if (strcmp(newStaff.religion, "islam") != 0 &&
            strcmp(newStaff.religion, "buddhism") != 0 &&
            strcmp(newStaff.religion, "christianity") != 0 &&
            strcmp(newStaff.religion, "hinduism") != 0 &&
            strcmp(newStaff.religion, "none") != 0) {
            red();
            printf("Invalid religion. Please enter one of the valid options.\n");
            black();
        }
    } while (strcmp(newStaff.religion, "islam") != 0 &&
        strcmp(newStaff.religion, "buddhism") != 0 &&
        strcmp(newStaff.religion, "christianity") != 0 &&
        strcmp(newStaff.religion, "hinduism") != 0 &&
        strcmp(newStaff.religion, "none") != 0);


    do {
        printf("Enter phone number (No need to put '-'): ");
        scanf("%[^\n]", newStaff.phoneNumber);
        rewind(stdin);

        isValid = 1;
        for (int i = 0; newStaff.phoneNumber[i] != '\0'; i++) {
            if (!isdigit(newStaff.phoneNumber[i])) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            red();
            printf("Invalid input. Please enter a numeric phone number without '-'.\n");
            black();
        }
    } while (!isValid);

    isValid = 0;

    do {
        printf("Enter age: ");
        scanf("%s", newStaff.age);
        rewind(stdin);

        isValid = 1;
        for (int i = 0; newStaff.age[i] != '\0'; i++) {
            if (!isdigit(newStaff.age[i])) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            red();
            printf("Invalid input. Please enter a numeric phone number without '-'.\n");
            black();
        }
    } while (!isValid);

    FILE* file = fopen("staff_information.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(-1);
    }
    fprintf(file, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", regStaffID, newStaff.staffName, newStaff.password, newStaff.passwordRecovery, newStaff.email, newStaff.position, newStaff.ic, newStaff.religion, newStaff.phoneNumber, newStaff.age);
    fclose(file);

    green();
    printf("\nRegister Successfully.\n");
    printf("Staff information saved to file.\n");
    black();
    do {
        printf("\nEnter (-1) to exit: ");
        scanf("%d", &exitInput);
        rewind(stdin);
        if (exitInput != -1) {
            red();
            printf("Invalid. Please enter again!!!\n");
            black();
        }
    } while (exitInput != -1);
    system("cls");
}

void staffActionMenu(staff loggedInStaff) {
    int choice;
    do {
        printf("Staff Management System\n");
        printf("--------------------------\n");
        printf("1. Add staff\n");
        printf("2. Search staff\n");
        printf("3. Modify staff\n");
        printf("4. Display staff\n");
        printf("5. Delete staff\n");
        printf("6. Staff Action History\n");
        printf("0. Exit\n");
        printf("\nSelect your choice > ");
        scanf("%d", &choice);
        rewind(stdin);

        switch (choice) {
        case 1:
            system("cls");
            addStaffData(loggedInStaff);
            break;
        case 2:
            system("cls");
            searchStaffData();
            break;
        case 3:
            system("cls");
            modifyStaffData(loggedInStaff);
            break;
        case 4:
            system("cls");
            displayStaffData();
            break;
        case 5:
            system("cls");
            deleteStaffData(loggedInStaff);
            break;
        case 6:
            system("cls");
            displayActionHistory();
            break;
        case 0:
            system("cls");
            break;
        default:
            red();
            printf("\nInvalid choice\n");
            printf("Enter again\n");
            black();
        }
    } while (choice != 0);
}

void staffLogin() {
    FILE* fptr = fopen("staff_information.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(-1);
    }
    staff checkLogin;
    char enteredStaffId[20];
    char enteredPassword[20];
    int found = 0;
    int exitInput;

    printf("Staff Login\n");
    printf("-------------\n");
    printf("Enter your ID: ");
    scanf("%s", enteredStaffId);
    rewind(stdin);
    while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", checkLogin.staffID, checkLogin.staffName, checkLogin.password, checkLogin.passwordRecovery, checkLogin.email, checkLogin.position, checkLogin.ic, checkLogin.religion, &checkLogin.phoneNumber, &checkLogin.age) != EOF) {
        if (strcmp(enteredStaffId, checkLogin.staffID) == 0) {
            found = 1;
            printf("Enter password: ");
            scanf("%[^\n]", enteredPassword);
            rewind(stdin);
            if (strcmp(enteredPassword, checkLogin.password) == 0) {
                if (strcmp(checkLogin.position, "ADM") == 0) {
                    green();
                    printf("Login Successful!\n\n");
                    black();
                    fclose(fptr);
                    staffActionMenu(checkLogin);
                }
                else {
                    red();
                    printf("\nYou don't have permission to access this function.\n");
                    black();
                    do {
                        printf("\nEnter -1 to exit: ");
                        scanf("%d", &exitInput);
                        rewind(stdin);
                        if (exitInput != -1) {
                            red();
                            printf("\nEnter again.");
                            black();
                        }

                    } while (exitInput != -1);
                    system("cls");
                    fclose(fptr);
                }
            }
            else {
                red();
                printf("Incorrect password.\n");
                black();
                do {
                    printf("\nEnter -1 to exit: ");
                    scanf("%d", &exitInput);
                    rewind(stdin);
                    if (exitInput != -1) {
                        red();
                        printf("\nEnter again.");
                        black();
                    }

                } while (exitInput != -1);
                system("cls");
                fclose(fptr);
            }
        }
    }
    fclose(fptr);
    if (!found) {
        red();
        printf("\nID not found.\n");
        printf("Please try again\n\n");
        black();
        do {
            printf("\nEnter -1 to exit: ");
            scanf("%d", &exitInput);
            rewind(stdin);
            if (exitInput != -1) {
                red();
                printf("\nEnter again.");
                black();
            }

        } while (exitInput != -1);
        system("cls");
    }
}

void addStaffData(staff loggedInStaff) {
    FILE* fptr = fopen("staff_information.txt", "r");
    FILE* file = fopen("staff_information.txt", "a");
    FILE* historyFile = fopen("staff_action_history.txt", "a");

    if (fptr == NULL || file == NULL || historyFile == NULL) {
        printf("Error opening file.\n");
        exit(-1);
    }

    staff addStaff;
    char addStaffID[20];
    int exit;
    int isValid = 0;

    printf("Staff ADD\n");
    printf("-----------------\n");

    do {
        printf("Enter staff ID in (STFXXX): ");
        scanf("%s", addStaffID);
        rewind(stdin);
        if (strlen(addStaffID) != 6 || strncmp(addStaffID, "STF", 3) != 0) {
            red();
            printf("Invalid staff ID format. Please enter in STFXXX format.\n");
            black();
        }
        else {
            rewind(fptr);
            while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|\n]\n", addStaff.staffID, addStaff.staffName, addStaff.password, addStaff.passwordRecovery, addStaff.email, addStaff.position, addStaff.ic, addStaff.religion, &addStaff.phoneNumber, &addStaff.age) != EOF) {
                if (strcmp(addStaff.staffID, addStaffID) == 0) {
                    red();
                    printf("\nStaff ID has been registered.\n");
                    printf("Please enter again.\n\n");
                    black();
                    break;
                }
            }
        }
    } while (strlen(addStaffID) != 6 || strncmp(addStaffID, "STF", 3) != 0 || strcmp(addStaff.staffID, addStaffID) == 0);
    fclose(fptr);

    printf("Enter Name: ");
    scanf("%[^\n]", addStaff.staffName);
    rewind(stdin);

    printf("Enter password: ");
    scanf("%s", addStaff.password);
    rewind(stdin);

    printf("Enter password recovery: ");
    scanf("%s", addStaff.passwordRecovery);
    rewind(stdin);

    int atIndex = -1;

    do {
        printf("Enter email (must in @gmail.com): ");
        scanf("%s", addStaff.email);
        rewind(stdin);

        int len = strlen(addStaff.email);

        for (int i = 0; i < len; i++) {
            if (addStaff.email[i] == '@') {
                atIndex = i;
                break;
            }
        }

        if (atIndex == -1 || strcmp(addStaff.email + atIndex + 1, "gmail.com") != 0) {
            red();
            printf("Invalid email format\n");
            black();
        }
    } while (atIndex == -1 || strcmp(addStaff.email + atIndex + 1, "gmail.com") != 0);

    do {
        printf("Enter position (ADM for ADMIN, STF for STAFF): ");
        scanf("%s", addStaff.position);
        rewind(stdin);
        if (strcmp(addStaff.position, "ADM") != 0 && strcmp(addStaff.position, "STF") != 0) {
            red();
            printf("Please enter a valid position!\n");
            black();
        }
    } while (strcmp(addStaff.position, "ADM") != 0 && strcmp(addStaff.position, "STF") != 0);

    do {
        printf("Enter IC in (YYMMDD-PB-###G): ");
        scanf("%[^\n]", addStaff.ic);
        rewind(stdin);
        if (strlen(addStaff.ic) != 14) {
            red();
            printf("Invalid IC format. Please enter in YYMMDD-PB-###G format.\n");
            black();
        }

        if (addStaff.ic[6] != '-' || addStaff.ic[9] != '-') {
            red();
            printf("Invalid IC format. Please enter in YYMMDD-PB-###G format.\n");
            black();
        }
    } while (strlen(addStaff.ic) != 14 || addStaff.ic[6] != '-' || addStaff.ic[9] != '-');

    do {
        printf("Enter religion (Islam/Buddhism/Christianity/Hinduism/None): ");
        scanf("%s", addStaff.religion);
        rewind(stdin);

        for (int i = 0; addStaff.religion[i]; i++) {
            addStaff.religion[i] = tolower(addStaff.religion[i]);
        }

        if (strcmp(addStaff.religion, "islam") != 0 &&
            strcmp(addStaff.religion, "buddhism") != 0 &&
            strcmp(addStaff.religion, "christianity") != 0 &&
            strcmp(addStaff.religion, "hinduism") != 0 &&
            strcmp(addStaff.religion, "none") != 0) {
            red();
            printf("Invalid religion. Please enter one of the valid options.\n");
            black();
        }
    } while (strcmp(addStaff.religion, "islam") != 0 &&
        strcmp(addStaff.religion, "buddhism") != 0 &&
        strcmp(addStaff.religion, "christianity") != 0 &&
        strcmp(addStaff.religion, "hinduism") != 0 &&
        strcmp(addStaff.religion, "none") != 0);

    do {
        printf("Enter phone number (No need to put '-'): ");
        scanf("%s", addStaff.phoneNumber);
        rewind(stdin);

        isValid = 1;
        for (int i = 0; addStaff.phoneNumber[i] != '\0'; i++) {
            if (!isdigit(addStaff.phoneNumber[i])) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            red();
            printf("Invalid input. Please enter a numeric phone number without '-'.\n");
            black();
        }
    } while (!isValid);

    isValid = 0;

    do {
        printf("Enter age: ");
        scanf("%s", addStaff.age);
        rewind(stdin);

        isValid = 1;
        for (int i = 0; addStaff.age[i] != '\0'; i++) {
            if (!isdigit(addStaff.age[i])) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            red();
            printf("Invalid input. Please enter a numeric age.\n");
            black();
        }
    } while (!isValid);

    fprintf(file, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", addStaffID, addStaff.staffName, addStaff.password, addStaff.passwordRecovery, addStaff.email, addStaff.position, addStaff.ic, addStaff.religion, addStaff.phoneNumber, addStaff.age);
    fclose(file);

    fprintf(historyFile, "%s|%s|added|%s|%s\n", loggedInStaff.staffName, loggedInStaff.staffID, addStaff.staffName, addStaffID);
    fclose(historyFile);


    green();
    printf("\nStaff Added Successfully.\n");
    printf("Staff information saved to file.\n");
    black();

    do {
        printf("\nEnter (-1) to exit: ");
        scanf("%d", &exit);
        rewind(stdin);
        if (exit != -1) {
            red();
            printf("Invalid. Please enter again!!!\n");
            black();
        }
    } while (exit != -1);
    system("cls");
}

void modifyStaffData(staff loggedInStaff) {
    FILE* fptr = fopen("staff_information.txt", "r");
    FILE* historyFile = fopen("staff_action_history.txt", "a");
    FILE* temp = fopen("temp.txt", "w");

    if (fptr == NULL || historyFile == NULL || temp == NULL) {
        printf("FILE NOT EXIST!!!");
        exit(-1);
    }

    char enteredStaffID[7];
    staff existingStaff;
    int found;
    char choice;
    int modifyChoice;
    int atIndex = -1;
    int isValid;

    do {
        found = 0;
        printf("Enter Staff ID to modify: ");
        scanf("%s", enteredStaffID);
        rewind(stdin);

        while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, &existingStaff.phoneNumber, &existingStaff.age) != EOF) {
            if (strcmp(enteredStaffID, existingStaff.staffID) == 0) {
                found = 1;
                green();
                printf("\nID FOUND\n\n");
                black();
                printf("Staff Name  : %s\n", existingStaff.staffName);
                printf("Email       : %s\n", existingStaff.email);
                printf("Position    : %s\n", existingStaff.position);
                printf("IC          : %s\n", existingStaff.ic);
                printf("Religion    : %s\n", existingStaff.religion);
                printf("Phone Number: %s\n", existingStaff.phoneNumber);
                printf("Age         : %s\n", existingStaff.age);

                do {
                    printf("\nWhat do you want to modify?\n");
                    printf("1. Name\n");
                    printf("2. Password\n");
                    printf("3. Password Recovery\n");
                    printf("4. Email\n");
                    printf("5. Position\n");
                    printf("6. IC\n");
                    printf("7. Religion\n");
                    printf("8. Phone Number\n");
                    printf("9. Age\n");
                    printf("0. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &modifyChoice);
                    rewind(stdin);
                    system("cls");

                    switch (modifyChoice) {
                    case 1:
                        printf("Enter new name: ");
                        scanf("%[^\n]", existingStaff.staffName);
                        rewind(stdin);
                        printf("Modification successful!\n");
                        break;
                    case 2:
                        printf("Enter new password: ");
                        scanf("%s", existingStaff.password);
                        rewind(stdin);
                        printf("Modification successful!\n");
                        break;
                    case 3:
                        printf("Enter new password recovery: ");
                        scanf("%s", existingStaff.passwordRecovery);
                        rewind(stdin);
                        printf("Modification successful!\n");
                        break;
                    case 4:
                        do {
                            printf("Enter new email (must in @gmail.com): ");
                            scanf("%s", existingStaff.email);
                            rewind(stdin);

                            int len = strlen(existingStaff.email);

                            for (int i = 0; i < len; i++) {
                                if (existingStaff.email[i] == '@') {
                                    atIndex = i;
                                    break;
                                }
                            }

                            if (atIndex == -1 || strcmp(existingStaff.email + atIndex + 1, "gmail.com") != 0) {
                                red();
                                printf("Invalid email format\n");
                                black();
                            }
                        } while (atIndex == -1 || strcmp(existingStaff.email + atIndex + 1, "gmail.com") != 0);
                        printf("Modification successful!\n");
                        break;
                    case 5:
                        do {
                            printf("Enter new position (ADM for ADMIN, STF for STAFF): ");
                            scanf("%s", existingStaff.position);
                            rewind(stdin);
                            if (strcmp(existingStaff.position, "ADM") != 0 && strcmp(existingStaff.position, "STF") != 0) {
                                red();
                                printf("Please enter a valid position!\n");
                                black();
                            }
                        } while (strcmp(existingStaff.position, "ADM") != 0 && strcmp(existingStaff.position, "STF") != 0);
                        printf("Modification successful!\n");
                        break;
                    case 6:
                        do {
                            printf("Enter new IC in (YYMMDD-PB-###G): ");
                            scanf("%[^\n]", existingStaff.ic);
                            rewind(stdin);
                            if (strlen(existingStaff.ic) != 14) {
                                red();
                                printf("Invalid IC format. Please enter in YYMMDD-PB-###G format.\n");
                                black();
                            }

                            if (existingStaff.ic[6] != '-' || existingStaff.ic[9] != '-') {
                                red();
                                printf("Invalid IC format. Please enter in YYMMDD-PB-###G format.\n");
                                black();
                            }
                        } while (strlen(existingStaff.ic) != 14 || existingStaff.ic[6] != '-' || existingStaff.ic[9] != '-');
                        printf("Modification successful!\n");
                        break;
                    case 7:
                        do {
                            printf("Enter new religion (Islam/Buddhism/Christianity/Hinduism/None): ");
                            scanf("%s", existingStaff.religion);
                            rewind(stdin);

                            for (int i = 0; existingStaff.religion[i]; i++) {
                                existingStaff.religion[i] = tolower(existingStaff.religion[i]);
                            }

                            if (strcmp(existingStaff.religion, "islam") != 0 &&
                                strcmp(existingStaff.religion, "buddhism") != 0 &&
                                strcmp(existingStaff.religion, "christianity") != 0 &&
                                strcmp(existingStaff.religion, "hinduism") != 0 &&
                                strcmp(existingStaff.religion, "none") != 0) {
                                red();
                                printf("Invalid religion. Please enter one of the valid options.\n");
                                black();
                            }
                        } while (strcmp(existingStaff.religion, "islam") != 0 &&
                            strcmp(existingStaff.religion, "buddhism") != 0 &&
                            strcmp(existingStaff.religion, "christianity") != 0 &&
                            strcmp(existingStaff.religion, "hinduism") != 0 &&
                            strcmp(existingStaff.religion, "none") != 0);
                        printf("Modification successful!\n");
                        break;
                    case 8:
                        isValid = 0;

                        do {
                            printf("Enter new phone number (No need to put '-'): ");
                            scanf("%s", existingStaff.phoneNumber);
                            rewind(stdin);

                            isValid = 1;
                            for (int i = 0; existingStaff.phoneNumber[i] != '\0'; i++) {
                                if (!isdigit(existingStaff.phoneNumber[i])) {
                                    isValid = 0;
                                    break;
                                }
                            }

                            if (!isValid) {
                                red();
                                printf("Invalid input. Please enter a numeric phone number without '-'.\n");
                                black();
                            }
                        } while (!isValid);
                        printf("Modification successful!\n");
                        break;
                    case 9:
                        isValid = 0;

                        do {
                            printf("Enter age: ");
                            scanf("%s", existingStaff.age);
                            rewind(stdin);

                            isValid = 1;
                            for (int i = 0; existingStaff.age[i] != '\0'; i++) {
                                if (!isdigit(existingStaff.age[i])) {
                                    isValid = 0;
                                    break;
                                }
                            }

                            if (!isValid) {
                                red();
                                printf("Invalid input. Please enter a numeric age.\n");
                                black();
                            }
                        } while (!isValid);
                        printf("Modification successful!\n");
                        break;
                    case 0:
                        system("cls");
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                    }
                } while (modifyChoice != 0);
                fprintf(historyFile, "%s|%s|modified|%s|%s\n", loggedInStaff.staffName, loggedInStaff.staffID, existingStaff.staffName, enteredStaffID);
            }
            fprintf(temp, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, existingStaff.phoneNumber, existingStaff.age);
        }

        if (!found) {
            red();
            printf("ID NOT FOUND!\n");
            black();
        }

        do {
            printf("\nDo you still want to modify anyone? (Y/N): ");
            scanf("%c", &choice);
            choice = toupper(choice);
            rewind(stdin);
            system("cls");
        } while (choice != 'Y' && choice != 'N');

    } while (choice == 'Y');

    fclose(fptr);
    fclose(temp);
    fclose(historyFile);

    remove("staff_information.txt");
    rename("temp.txt", "staff_information.txt");
}

void searchStaffData() {
    int choice;
    do {
        printf("Search Staff Data\n");
        printf("-------------------\n");
        printf("What do you want to search for ?\n");
        printf("1. Staff ID\n");
        printf("2. IC\n");
        printf("3. Phone Number\n");
        printf("4. Exit\n");
        printf("Enter your choice > ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");
            searchID();
            break;
        case 2:
            system("cls");
            searchIC();
            break;
        case 3:
            system("cls");
            searchPhoneNumber();
            break;
        case 4:
            system("cls");
            break;
        default:
            red();
            printf("Invalid choice\n");
            printf("Enter again\n\n");
            black();
        }
    } while (choice != 4);
}

void searchID() {
    char enteredStaffID[7];
    staff existingStaff;
    char choice;
    int found;
    FILE* fptr = fopen("staff_information.txt", "r");

    do {
        found = 0;
        printf("Enter Staff ID to search: ");
        scanf("%s", enteredStaffID);
        rewind(stdin);

        rewind(fptr);

        while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, &existingStaff.phoneNumber, &existingStaff.age) != EOF) {
            if (strcmp(enteredStaffID, existingStaff.staffID) == 0) {
                found = 1;
                green();
                printf("\nID FOUND\n\n");
                black();
                printf("Staff Name  : %s\n", existingStaff.staffName);
                printf("Email       : %s\n", existingStaff.email);
                printf("Position    : %s\n", existingStaff.position);
                printf("IC          : %s\n", existingStaff.ic);
                printf("Religion    : %s\n", existingStaff.religion);
                printf("Phone Number: %s\n", existingStaff.phoneNumber);
                printf("Age         : %s\n", existingStaff.age);
            }
        }

        if (!found) {
            red();
            printf("ID NOT FOUND!\n");
            black();
        }

        do {
            printf("Do you still want to search? (Y/N): ");
            scanf("%c", &choice);
            choice = toupper(choice);
            rewind(stdin);
            system("cls");
        } while (choice != 'Y' && choice != 'N');

    } while (choice == 'Y');
    fclose(fptr);
}

void searchIC() {
    char enteredStaffIC[15];
    staff existingStaff;
    char choice;
    int found;
    FILE* fptr = fopen("staff_information.txt", "r");

    do {
        found = 0;
        printf("Enter IC to search: ");
        scanf("%s", enteredStaffIC);
        rewind(stdin);

        rewind(fptr);

        while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, &existingStaff.phoneNumber, &existingStaff.age) != EOF) {
            if (strcmp(enteredStaffIC, existingStaff.ic) == 0) {
                found = 1;
                green();
                printf("\nIC FOUND\n\n");
                black();
                printf("Staff ID          : %s\n", existingStaff.staffID);
                printf("Name              : %s\n", existingStaff.staffName);
                printf("Email             : %s\n", existingStaff.email);
                printf("Position          : %s\n", existingStaff.position);
                printf("Religion          : %s\n", existingStaff.religion);
                printf("Phone Number      : %s\n", existingStaff.phoneNumber);
                printf("Age               : %s\n", existingStaff.age);
            }
        }

        if (!found) {
            red();
            printf("IC NOT FOUND!\n");
            black();
        }

        do {
            printf("Do you still want to search? (Y/N): ");
            scanf("%c", &choice);
            choice = toupper(choice);
            rewind(stdin);
            system("cls");
        } while (choice != 'Y' && choice != 'N');

    } while (choice == 'Y');
    fclose(fptr);
}

void searchPhoneNumber() {
    int enteredPhoneNumber;
    staff existingStaff;
    char choice;
    int found;
    FILE* fptr = fopen("staff_information.txt", "r");

    do {
        found = 0;
        printf("Enter Phone Number to search: ");
        scanf("%s", &enteredPhoneNumber);
        rewind(stdin);

        rewind(fptr);

        while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, &existingStaff.phoneNumber, &existingStaff.age) != EOF) {
            if (enteredPhoneNumber == existingStaff.phoneNumber) {
                found = 1;
                green();
                printf("\nNUMBER FOUND\n\n");
                black();
                printf("Staff ID          : %s\n", existingStaff.staffID);
                printf("Name              : %s\n", existingStaff.staffName);
                printf("Email             : %s\n", existingStaff.email);
                printf("IC                : %s\n", existingStaff.ic);
                printf("Position          : %s\n", existingStaff.position);
                printf("Religion          : %s\n", existingStaff.religion);
                printf("Age               : %s\n", existingStaff.age);
            }
        }

        if (!found) {
            red();
            printf("PHONE NUMBER NOT FOUND!\n");
            black();
        }

        do {
            printf("Do you still want to search? (Y/N): ");
            scanf("%c", &choice);
            choice = toupper(choice);
            rewind(stdin);
            system("cls");
        } while (choice != 'Y' && choice != 'N');

    } while (choice == 'Y');
    fclose(fptr);
}

void displayStaffData() {
    FILE* fptr = fopen("staff_information.txt", "r");
    staff displayStaff;

    if (fptr == NULL) {
        printf("FILE NOT EXIST!!!");
        exit(-1);
    }

    int exit;

    printf("                                                          STAFF DATA\n");
    printf(" -------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s %-20s %-20s %-15s %-17s %-10s %-15s %-5s |\n", "Staff ID", "Name", "Email", "Position", "IC", "Religion", "Phone Number", "Age");
    printf(" -------------------------------------------------------------------------------------------------------------------------\n");
    while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", displayStaff.staffID, displayStaff.staffName, displayStaff.password, displayStaff.passwordRecovery, displayStaff.email, displayStaff.position, displayStaff.ic, displayStaff.religion, &displayStaff.phoneNumber, &displayStaff.age) != EOF) {
        printf("| %-10s %-20s %-20s %-15s %-17s %-10s %-15s %-5s |\n", displayStaff.staffID, displayStaff.staffName, displayStaff.email, displayStaff.position, displayStaff.ic, displayStaff.religion, displayStaff.phoneNumber, displayStaff.age);
    }
    printf(" -------------------------------------------------------------------------------------------------------------------------\n");
    fclose(fptr);

    do {
        printf("\nEnter (-1) to exit: ");
        scanf("%d", &exit);
        rewind(stdin);
        if (exit != -1) {
            red();
            printf("Invalid. Please enter again!!!\n");
            black();
        }
    } while (exit != -1);

    system("cls");
}

void deleteStaffData(staff loggedInStaff) {
    FILE* fptr = fopen("staff_information.txt", "r");
    FILE* historyFile = fopen("staff_action_history.txt", "a");


    if (fptr == NULL || historyFile == NULL) {
        printf("Error opening file.\n");
        exit(-1);
    }

    char enteredStaffID[7];
    staff existingStaff;
    int found = 0;
    char confirm;
    int exitInput;
    int count = 0;
    int indexToRemove = 0;
    int staffCount = 0;
    staff temp[100];


    while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, existingStaff.phoneNumber, existingStaff.age) != EOF) {
        temp[staffCount++] = existingStaff;
    }

    printf("Enter Staff ID to delete: ");
    scanf("%s", enteredStaffID);
    rewind(stdin);

    rewind(fptr);

    while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, existingStaff.phoneNumber, existingStaff.age) != EOF) {
        count++;
        if (strcmp(enteredStaffID, existingStaff.staffID) == 0) {
            found = 1;
            indexToRemove = count - 1;
            green();
            printf("\nStaff ID %s found.\n", enteredStaffID);
            black();
            printf("Staff Information:\n");
            printf("Name        : %s\n", existingStaff.staffName);
            printf("Email       : %s\n", existingStaff.email);
            printf("Position    : %s\n", existingStaff.position);
            printf("IC          : %s\n", existingStaff.ic);
            printf("Religion    : %s\n", existingStaff.religion);
            printf("Phone Number: %s\n", existingStaff.phoneNumber);
            printf("Age         : %s\n", existingStaff.age);

            printf("Are you sure you want to delete this staff (Y/N)? ");
            scanf("%c", &confirm);
            rewind(stdin);
            if (toupper(confirm) == 'Y') {
                printf("\nStaff ID %s deleted.\n", enteredStaffID);
                fprintf(historyFile, "%s|%s|deleted|%s|%s\n", loggedInStaff.staffName, loggedInStaff.staffID, existingStaff.staffName, enteredStaffID);
                fclose(historyFile);

                for (int i = indexToRemove; i < staffCount - 1; i++) {
                    temp[i] = temp[i + 1];
                }

                fclose(fptr);
                FILE* fptr2 = fopen("staff_information.txt", "w");
                for (int i = 0; i < staffCount - 1; i++) {
                    fprintf(fptr2, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", temp[i].staffID, temp[i].staffName, temp[i].password, temp[i].passwordRecovery, temp[i].email, temp[i].position, temp[i].ic, temp[i].religion, temp[i].phoneNumber, temp[i].age);
                }
                fclose(fptr2);

                do {
                    printf("\nEnter (-1) to exit: ");
                    scanf("%d", &exitInput);
                    rewind(stdin);
                    if (exitInput != -1) {
                        red();
                        printf("Invalid. Please enter again!!!\n");
                        black();
                    }
                    system("cls");
                } while (exitInput != -1);
            }
            else {
                printf("\nDeletion canceled.\n");
                do {
                    printf("\nEnter (-1) to exit: ");
                    scanf("%d", &exitInput);
                    rewind(stdin);
                    if (exitInput != -1) {
                        red();
                        printf("Invalid. Please enter again!!!\n");
                        black();
                    }
                    system("cls");
                } while (exitInput != -1);
            }

        }
    }


    if (!found) {
        red();
        printf("\nID not found.\n");
        printf("Please try again\n\n");
        black();
        do {
            printf("\nEnter -1 to exit: ");
            scanf("%d", &exitInput);
            rewind(stdin);
            if (exitInput != -1) {
                red();
                printf("\nEnter again.");
                black();
            }

        } while (exitInput != -1);
        system("cls");
    }
    fclose(historyFile);
    fclose(fptr);
}

void displayActionHistory() {
    staff data;
    FILE* fptr = fopen("staff_action_history.txt", "r");

    if (fptr == NULL) {
        printf("No staff action history found.\n");
        exit(-1);
    }

    int exit;

    printf("                                            Staff Action History\n");
    printf("=======================================================================================================================\n");
    printf("| %-20s | %-20s | %-20s | %-25s | %-11s |\n", "Name", "ID", "Action", "Staff Name Affected", "Staff ID Affected");
    printf("=======================================================================================================================\n");

    while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", &data.staffName, &data.staffID, &data.action, &data.staffAffectedName, &data.staffAffectedID) != EOF) {
        printf("| %-20s | %-20s | %-20s | %-25s | %-18s |\n", data.staffName, data.staffID, data.action, data.staffAffectedName, data.staffAffectedID);
    }

    printf("=======================================================================================================================\n");

    fclose(fptr);

    do {
        printf("\nEnter (-1) to exit: ");
        scanf("%d", &exit);
        rewind(stdin);
        if (exit != -1) {
            red();
            printf("Invalid. Please enter again!!!\n");
            black();
        }
    } while (exit != -1);
    system("cls");
}

void passwordRecovery() {
    FILE* fptr = fopen("staff_information.txt", "r");
    FILE* temp = fopen("temp.txt", "w");

    if (fptr == NULL || temp == NULL) {
        printf("FILE NOT EXIST!!!");
        exit(-1);
    }

    char enteredStaffID[7];
    char enteredPasswordRecovery[20];
    char enteredPassword[20];
    staff existingStaff;
    int found = 0;
    int exit;

    printf("Password Recovery\n");
    printf("-------------------\n");
    printf("Enter your Staff ID: ");
    scanf("%s", enteredStaffID);
    rewind(stdin);
    while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|\n]\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, &existingStaff.phoneNumber, &existingStaff.age) != EOF) {
        if (strcmp(enteredStaffID, existingStaff.staffID) == 0) {
            found = 1;
            printf("Enter your Password Recovery: ");
            scanf("%s", enteredPasswordRecovery);
            rewind(stdin);
            if (strcmp(enteredPasswordRecovery, existingStaff.passwordRecovery) == 0) {
                printf("Enter new password: ");
                scanf("%s", enteredPassword);
                rewind(stdin);
                strcpy(existingStaff.password, enteredPassword);
                green();
                printf("Password updated successfully.\n");
                black();
                do {
                    printf("\nEnter -1 to exit: ");
                    scanf("%d", &exit);
                    rewind(stdin);
                    if (exit != -1) {
                        red();
                        printf("\nEnter again.");
                        black();
                    }
                } while (exit != -1);
                system("cls");
            }
            else {
                red();
                printf("Password Recovery Not Match.\n");
                black();
                do {
                    printf("\nEnter -1 to exit: ");
                    scanf("%d", &exit);
                    rewind(stdin);
                    if (exit != -1) {
                        red();
                        printf("\nEnter again.");
                        black();
                    }
                } while (exit != -1);
                system("cls");
            }
            fprintf(temp, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, existingStaff.phoneNumber, existingStaff.age);
        }
        else {
            fprintf(temp, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", existingStaff.staffID, existingStaff.staffName, existingStaff.password, existingStaff.passwordRecovery, existingStaff.email, existingStaff.position, existingStaff.ic, existingStaff.religion, existingStaff.phoneNumber, existingStaff.age);
        }
    }

    fclose(fptr);
    fclose(temp);

    remove("staff_information.txt");
    rename("temp.txt", "staff_information.txt");

    if (!found) {
        red();
        printf("Staff ID not found. Please try again.\n\n");
        black();
        do {
            printf("\nEnter -1 to exit: ");
            scanf("%d", &exit);
            rewind(stdin);
            if (exit != -1) {
                red();
                printf("\nEnter again.");
                black();
            }
        } while (exit != -1);
        system("cls");
    }
}

void red() {
    printf("\033[1;31m");
}

void green() {
    printf("\033[0;32m");
}

void black() {
    printf("\033[0;30m");
}