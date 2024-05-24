#include <stdio.h>
#include <stdlib.h>                            
#include <string.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;



typedef struct Trip
{
    char destination[50];
    Date departure_date;
    Date return_date;
    float cost;
    struct Trip *next;
} Trip;



typedef struct User
{
    char username[50];
    char password[50];
    float balance;
    char booked_trip[50];
    struct User *next;
} User;







// function prototype...................................

void userMenu(User **users, Trip **head);
void adminMenu(Trip **head);
void addTrip(Trip **head);
void displayAllTrips(Trip *head);
void freeList(Trip *head);
void saveTripsToFile(Trip *head, const char *filename);
Trip *loadTripsFromFile(const char *filename);
void signUp(User **head);
void login(User **users);
void bookTrip(User *user, Trip **head, const char *filename);
void cancelTrip(User *user);
void checkTicket(User *user);
void savePurchaseHistory(User *user, Trip *trip);


void clearScreen()
{
    system("cls");
}






int main()
{
    Trip *head = NULL;
    User *users = NULL;
    int choice;
    head = loadTripsFromFile("trips.txt"); // sir .. head holo trip er txt file ta ........

    do
    {
        clearScreen();

        printf("\033[0;32m"); // ANSI code........................Green text

        printf("\n\n\n\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t||            Tourism and Travel Management         ||\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t||                                                   ||\n");
        printf("\t\t\t\t||            1. User Menu                           ||\n");
        printf("\t\t\t\t||            2. Admin Menu                          ||\n");
        printf("\t\t\t\t||            3. Developer Info                      ||\n");
        printf("\t\t\t\t||            4. Exit                                ||\n");
        printf("\t\t\t\t||                                                   ||\n");
        printf("\t\t\t\t=======================================================\n");

        printf("\033[5;31m"); // Blinking red text ANSI COde...............

        printf("\t\t\t\t|| Enter your choice: ");

        scanf("%d", &choice);

        printf("\033[0m"); // Reset text color to default.........ANSI

        switch (choice)
        {
        case 1:
            userMenu(&users, &head);
            break;
        case 2:
            adminMenu(&head);
            break;
        case 3:
            clearScreen();
            printf("\033[0;33m");
            printf("\n\n\n\n");
            printf("\t\t\t\t=======================================================\n");
            printf("\t\t\t\t||             Tourism and Travel Management         ||\n");
            printf("\t\t\t\t=======================================================\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||            Name :  Md.Mehedi Hasan                ||\n");
            printf("\t\t\t\t||            Email:- hasan2305101494@diu.edu.bd     ||\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||            Name :  Sumaiya Yesmin                 ||\n");
            printf("\t\t\t\t||            Email:- yesmin2305101141@diu.edu.bd    ||\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||            Name :  Maria Rashid                   ||\n");
            printf("\t\t\t\t||            Email:- maria2305101160@diu.edu.bd     ||\n ");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||            Name:   Sayma Islam                    ||\n");
            printf("\t\t\t\t||            Email:- sayma23051011511@diu.edu.bd    ||\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||            Name:   Mst. Sanjida Akter Trisha      ||\n");
            printf("\t\t\t\t||            Email:- trisha2305101451@diu.edu.bd    ||\n ");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t=======================================================\n");
            printf("Press any key to return...");

            getchar(); // incountering the space/,,,,,,,,,,,,,,,,,,
            getchar(); // Wait for user input
            break;
        case 4:
            printf("Exiting program...\n");
            freeList(head);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}












void userMenu(User **users, Trip **head) // pointer er pointer..............
{
    int choice;
    do
    {
        clearScreen();

        printf("\033[32m");         // ANSI code .................Green text

        printf("\n\n\n\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t||             Tourism and Travel Management         ||\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t||                                                   ||\n");
        printf("\t\t\t\t||               1. Sign Up                          ||\n");
        printf("\t\t\t\t||               2. Log In                           ||\n");
        printf("\t\t\t\t||               3. Back to Main Menu                ||\n");
        printf("\t\t\t\t=======================================================\n");

        printf("\033[0m");    // Reset text color to default
        printf("\033[0;36m"); // cyan color.................

        printf("\t\t\t\t|| Enter your choice: ");
        scanf("%d", &choice);

        printf("\033[0m"); // Reset text color to default

        switch (choice)
        {
        case 1:
            signUp(users);
            break;
        case 2:
            login(users);
            break;
        case 3:
            return; // Go back to the main menu
        default:
            printf("Invalid choice! Please try again.\n");
        }


    } while (choice != 3);
}









void adminMenu(Trip **head)
{
    int choice;
    char username[50];
    char password[50];

    clearScreen();
    printf("\033[0;32m"); // green color
    printf("\n\n\n\n");
    printf("\t\t\t\t=======================================================\n");
    printf("\t\t\t\t||             Tourism and Travel Management         ||\n");
    printf("\t\t\t\t=======================================================\n\n\n");
    printf("\033[0;31m"); // red color
    printf("\t\t\t\t|| Admin Area..... Unauthorized login not allowed.\n\n");
    printf("\033[0;32m"); // green color
    printf("\t\t\t\t                Enter username: ");
    scanf("%s", username);
    printf("\t\t\t\t                Enter password: ");
    scanf("%s", password);

    if (strcmp(username, "mehedi") == 0 && strcmp(password, "champa") == 0)
    {
        do
        {
            clearScreen();
            printf("\033[1;32m"); // Green color ANSI code
            printf("\n\n\n\n");
            printf("\t\t\t\t=======================================================\n");
            printf("\t\t\t\t||             Tourism and Travel Management         ||\n");
            printf("\t\t\t\t=======================================================\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t||               1. Add a Trip                       ||\n");
            printf("\t\t\t\t||               2. Display All Trips                ||\n");
            printf("\t\t\t\t||               3. Save Trips to File               ||\n");
            printf("\t\t\t\t||               4. Back to Main Menu                ||\n");
            printf("\t\t\t\t=======================================================\n");
            printf("\033[0m");    // Reset text color
            printf("\033[5;31m"); // Set text color to red and enable blinking
            printf("\t\t\t\t|| Enter your choice: ");
            scanf("%d", &choice);
            printf("\033[0m"); // Reset text color

            switch (choice)
            {
            case 1:
                clearScreen();
                addTrip(head);
                break;
            case 2:
                clearScreen();
                displayAllTrips(*head);
                printf("Press any key to return...");
                getchar(); // encountering new line
                getchar(); // Wait for user input
                break;

            case 3:
                saveTripsToFile(*head, "trips.txt");
                printf("Trips saved to file successfully!\n");
                
                sleep(2);
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
            }
        } while (choice != 4);
    }
    else
    {
        printf("Authentication failed. Invalid username or password.\n");
        sleep(2);
    }
}


















void addTrip(Trip **head) //
{
    Trip *newTrip = (Trip *)malloc(sizeof(Trip)); //

    if (newTrip == NULL)

    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter destination: ");
    getchar();

    fgets(newTrip->destination, sizeof(newTrip->destination), stdin);

    newTrip->destination[strcspn(newTrip->destination, "\n")] = '\0';

    printf("Enter departure date (DD MM YYYY): ");
    scanf("%d %d %d", &newTrip->departure_date.day, &newTrip->departure_date.month, &newTrip->departure_date.year);

    printf("Enter return date (DD MM YYYY): ");
    scanf("%d %d %d", &newTrip->return_date.day, &newTrip->return_date.month, &newTrip->return_date.year);

    printf("Enter cost: ");
    scanf("%f", &newTrip->cost);

    newTrip->next = *head;
    *head = newTrip;

    printf("Trip added successfully!\n");
    sleep(2);
}















void displayAllTrips(Trip *head) {
    if (head == NULL) {
        printf("No trips to display.\n");
        return;
    }

    printf("\033[0;32m"); // Green color

    printf("All Trips:\n");
    printf("=================================================================================\n");
    printf("%-20s %-15s %-15s %-10s\n", "Destination", "Departure Date", "Return Date", "Cost");
    printf("=================================================================================\n");

    while (head != NULL) {
        printf("%-20s %02d/%02d/%04d   %02d/%02d/%04d   $%-9.2f\n", head->destination,
               head->departure_date.day, head->departure_date.month, head->departure_date.year,
               head->return_date.day, head->return_date.month, head->return_date.year, head->cost);
        head = head->next;
    }

    printf("=================================================================================\n");
    printf("\033[0m"); // Reset text color
}












void freeList(Trip *head)
{
    Trip *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

















void saveTripsToFile(Trip *head, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    while (head != NULL)
    {
        fprintf(file, "%s %d %d %d %d %d %d %.2f\n", head->destination, head->departure_date.day,
                head->departure_date.month, head->departure_date.year, head->return_date.day,
                head->return_date.month, head->return_date.year, head->cost);
        head = head->next;
    }

    fclose(file);
}


















Trip *loadTripsFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return NULL;
    }

    Trip *head = NULL;
    char destination[50];
    Date departure_date, return_date;
    float cost;

    while (fscanf(file, "%s %d %d %d %d %d %d %f", destination, &departure_date.day,
                  &departure_date.month, &departure_date.year, &return_date.day,
                  &return_date.month, &return_date.year, &cost) == 8)
    {
        Trip *newTrip = (Trip *)malloc(sizeof(Trip));
        if (newTrip == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(file);
            freeList(head);
            return NULL;
        }

        strcpy(newTrip->destination, destination);
        newTrip->departure_date = departure_date;
        newTrip->return_date = return_date;
        newTrip->cost = cost;

        newTrip->next = head;
        head = newTrip;
    }

    fclose(file);
    return head;
}













void signUp(User **head)
{
    User *newUser = (User *)malloc(sizeof(User));
    if (newUser == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    clearScreen();
    printf("\n\n\n\n");
    printf("\t\t\t\t=======================================================\n");
    printf("\t\t\t\t||             Tourism and Travel Management         ||\n");
    printf("\t\t\t\t=======================================================\n\n\n");

    printf("\t\t\t\t                Enter username: ");
    scanf("%s", newUser->username);

    printf("\t\t\t\t                Enter password: ");
    scanf("%s", newUser->password);
    newUser->balance = 0;

    FILE *file = fopen("users.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        free(newUser);
        return;
    }
    fprintf(file, "%s %s %.2f\n", newUser->username, newUser->password, newUser->balance);
    fclose(file);

    newUser->next = *head;
    *head = newUser;
    printf("Account created successfully!\n");
    printf("Press any key to return...");
    getchar();
    getchar();
}











void login(User **users)
{
    char username[50];
    char password[50];

    clearScreen();

    printf("\t\t\t\t=======================================================\n");
    printf("\t\t\t\t||             Tourism and Travel Management         ||\n");
    printf("\t\t\t\t=======================================================\n\n\n");

    printf("\t\t\t\t                Enter username: ");
    scanf("%s", username);

    printf("\t\t\t\t                Enter Password: ");
    scanf("%s", password);

    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    char fileUsername[50];
    char filePassword[50];
    float balance;
    int found = 0;
    User *currentUser = NULL;

    while (fscanf(file, "%s %s %f", fileUsername, filePassword, &balance) == 3)
    {
        if (strcmp(fileUsername, username) == 0 && strcmp(filePassword, password) == 0)
        {
            printf("Login successful!\n");
            found = 1;

            User *current = *users;
            while (current != NULL)
            {
                if (strcmp(current->username, username) == 0)
                {
                    currentUser = current;
                    break;
                }
                current = current->next;
            }

            if (currentUser == NULL)
            {
                currentUser = (User *)malloc(sizeof(User));
                if (currentUser == NULL)
                {
                    printf("Memory allocation failed.\n");
                    fclose(file);
                    return;
                }
                strcpy(currentUser->username, username);
                strcpy(currentUser->password, password);
                currentUser->balance = balance;
                currentUser->next = *users;
                *users = currentUser;
            }
            break;
        }
    }

    fclose(file);

    if (!found)
    {
        printf("Login failed. Invalid username or password.\n");
        sleep(2);
        return;
    }

    int choice;
    do
    {
        clearScreen();
        printf("\033[32m"); // Green text
        printf("\n\n\n\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t||             Tourism and Travel Management         ||\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t||                                                   ||\n");
        printf("\t\t\t\t||               1. Book a Trip                      ||\n");
        printf("\t\t\t\t||               2. Cancel Trip                      ||\n");
        printf("\t\t\t\t||               3. Check Ticket                     ||\n");
        printf("\t\t\t\t||               4. Back to Main Menu                ||\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\033[0m"); // Reset text color

        printf("\t\t\t\t                Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bookTrip(currentUser, &(*users)->next, "trips.txt");
            break;
        case 2:
            cancelTrip(currentUser);
            break;
        case 3:
            checkTicket(currentUser);
            break;
        case 4:
            return;
        default:
            printf("Invalid choice! Please try again.\n");
            sleep(2);
            break;
        }
    } while (choice != 4);
}












void bookTrip(User *user, Trip **head, const char *filename)
{
    clearScreen();
    *head = loadTripsFromFile(filename);

    if (*head == NULL)
    {
        printf("No trips available.\n");
        printf("Press any key to return...");
        getchar();
        getchar();
        return;
    }

    printf("Available trips:\n");
    displayAllTrips(*head);

    char destination[50];
    printf("Enter destination to book: ");
    scanf("%s", destination);

    Trip *current = *head;
    while (current != NULL)
    {
        if (strcmp(current->destination, destination) == 0)
        {
            printf("Trip booked successfully!\n");
            strcpy(user->booked_trip, destination);
            savePurchaseHistory(user, current);
            printf("Ticket Details:\n");
            printf("Destination: %s\n", current->destination);
            printf("Departure Date: %02d/%02d/%04d\n", current->departure_date.day, current->departure_date.month, current->departure_date.year);
            printf("Return Date: %02d/%02d/%04d\n", current->return_date.day, current->return_date.month, current->return_date.year);
            printf("Cost: $%.2f\n", current->cost);
            printf("Press any key to return...");
            getchar();
            getchar();
            return;
        }
        current = current->next;
    }

    printf("Trip not found.\n");
    sleep(2);
}





void cancelTrip(User *user)
{
    clearScreen();

    if (user == NULL)
    {
        printf("Please log in first.\n");
        return;
    }

    printf("Canceling booked trip: %s\n", user->booked_trip);
    strcpy(user->booked_trip, "");
    printf("Trip canceled successfully.\n");
    sleep(2);
}











void checkTicket(User *user)
{
    clearScreen();

    if (user == NULL)
    {
        printf("Please log in first.\n");
        return;
    }

    if (strcmp(user->booked_trip, "") == 0)
    {
        printf("You haven't booked any trip yet.\n");
    }
    else
    {
        printf("Your booked trip: %s\n", user->booked_trip);
    }
    printf("Press any key to return...");
    getchar();
    getchar();
}










void savePurchaseHistory(User *user, Trip *trip)
{
    char filename[60];
    sprintf(filename, "%s_history.txt", user->username);

    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "Destination: %s, Departure Date: %02d/%02d/%04d, Return Date: %02d/%02d/%04d, Cost: %.2f\n",
            trip->destination, trip->departure_date.day, trip->departure_date.month, trip->departure_date.year,
            trip->return_date.day, trip->return_date.month, trip->return_date.year, trip->cost);

    fclose(file);
}
