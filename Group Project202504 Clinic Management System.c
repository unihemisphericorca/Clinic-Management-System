#include <stdio.h>
#include <string.h>

//declaring function used
void add_update();
void add();
void update();
void ScheduleAppointment();
void VisitRecord();
void Search();
void patient();
void appointment();
void history();
void file();



//main menu start
int main()
{
    int selection;
    
    file();
    
    do {
        printf("=== Clinic Management System ===\n");
        printf("1. Add or Update Patient\n2. Schedule Appointment\n3. Record Visit\n4. Search Records\n5. Exit\n>> ");//main menu, let user see what selection they have      
        scanf("%d", &selection);//user choose which action to do
        switch (selection) {
            case 1: add_update(); break;//user choose to add patient 
            case 2: ScheduleAppointment(); break;//user choose to schedule appointment
            case 3: VisitRecord(); break;//user choose to add vist records 
            case 4: Search(); break;//user choose to search 
            case 5: printf("Exiting...\n"); break;//user exit the program
            default: printf("\nInvalid option. Try again.\n\n"); break;//user type integer other than 1 to 5    //let user know their input is invalid
        }
    } while (selection != 5);//will loop until the user input integer 5
    return 0;
}
//main menu end




//create text file start
void file()
{
    FILE *f1;
    FILE *file2;
    FILE *f3;
    
    f1 = fopen("patients_data.txt", "a");       //Ensure patient_data.txt file exists
    fclose(f1);
    
    file2 = fopen("appointments.txt", "a");     //Ensure appointments.txt file exists
    fclose(file2);
    
    f3 = fopen("visit_records.txt", "a");       //Ensure visit_records.txt file exists
    fclose(f3);
}
//create text file end



//Add or update menu start
void add_update()
{
    int choice;
    
    
    do
    {
        printf("\n=== Patient Menu ===\n1. Add New Patient\n2. Update Existing Patient\n3. Return\n>> ");//patient menu, let user see what selection they have
        scanf("%d",&choice);//user enter which action to do
        switch (choice)
        {
            case(1):
            add();//user add patient
            break;
            case(2):
            update();//user update patient that exist
            break;
            case(3):
            printf("Returning to main menu...\n\n");//user exit patient menu    //let user know they are returning to main menu
            break;
            default: printf("\nInvalid option. Try again.\n\n"); break;//user type integer other than 1 to 3    //let user know their input was wrong
        }
    }
    while(choice!=3);//will loop until user input until integer 3 
}
//Add or update menu





// Add patient start
void add()
{
    FILE* file1;
    file1=fopen("patients_data.txt","a");//create file
    fclose(file1);
    file1=fopen("patients_data.txt","r");
    char PID[10],fname[20],lname[20],gender[10],contact[15],age[10];
    char PID2[10];int conflict;//declaring variable used
        conflict=1;
        printf("\n==Add Patient==\n");//let the user know they are in the add patient section
        printf("Enter Patient ID (P001,): ");
        scanf("%s", PID2);
        
        while(!feof(file1))
        {
            
            fscanf(file1,"%s,",PID);//scan data exist in patients_data.txt
            if (strcmp(PID2,PID) == 0)
            {
                printf("\nID is used! Please change ID!\n");
                conflict=0;
                break;
            }//prevent 2 same patient id exist in patients_data.txt
        }
        if (conflict==1)//continue to let user key in Information
        {
        printf("Enter First Name (e.g. Alice): ");
        scanf("%s", fname);
        printf("Enter Last Name (e.g. Smith): ");
        scanf("%s", lname);
        printf("Enter Age: ");
        scanf("%s", age);
        printf("Enter Gender (M/F): ");
        scanf("%s", gender);
        printf("Enter Contact Number: ");
        scanf("%s", contact);
        //user input patients data
            
            
            fclose(file1);
            strcpy(PID,PID2);
            file1=fopen("patients_data.txt","a");
            fprintf(file1,"%s %s, %s, %s, %s, %s\n", PID, fname, lname, age, gender, contact);//input user data into patients_data.txt
            printf("\nPatient added successfully!\n");
            fclose(file1);
        }

}
//Add patient end





//Update patient start
void update()
{
    FILE*file1;
    char PID[10],fname[20],lname[20],gender[10],contact[15],age[10];
    char PID3[100][10],firstname[100][20],lastname[100][20],gender3[100][10],contact3[100][15],age3[100][10];
    char PID2[10],fname2[20],lname2[20],gender2[10],contact2[15],age2[10];
    int found=0,i=0,b;//declare variable used 
    printf("\n==Update Patient Information==\n");
    printf("Enter Patient ID update(e.g. P001,): ");
    scanf("%s",PID2);//user enter patient to update //user need to add comma after patient id  in order to get the data found
    file1=fopen("patients_data.txt","r");
    
    //make previous data in patients_data.txt to array
   while (!feof(file1))
        {   
            fscanf(file1,"%s %s %s %s %s %s",PID,fname,lname,age,gender,contact);
            strcpy(PID3[i],PID);
            strcpy(firstname[i],fname);
            strcpy(lastname[i],lname);
            strcpy(age3[i],age);
            strcpy(gender3[i],gender);
            strcpy(contact3[i],contact);
           i++;
        }
        
        //find patient id to change 
    for(int c=0;c<i-1;c++)
            {
               
                if (strcmp(PID3[c],PID2)==0)
                {
                    //enter update information
                    printf("\n==Update Patient Information==\n");
                    printf("Enter Update First name (e.g. Alice,): ");
                    scanf("%s",fname2);
                    printf("Enter Update Last name (e.g. Smith,): ");
                    scanf("%s",lname2);
                    printf("Enter Update Age (e.g. 18,): ");
                    scanf("%s",age2);
                    printf("Enter Update Gender (M/F,): ");
                    scanf("%s",gender2);
                    printf("Enter Update Contact Number : ");
                    scanf("%s",contact2);
                    found=1;
                    break; 
                }
                b++;
            }
        fclose(file1);
        if (found==1)
        {
            //overwrite the whole file 
            FILE*file1;
            file1=fopen("patients_data.txt","w");
            for (int c=0;c<i-1;c++)
            {
                if (b==c)
                fprintf(file1,"%s %s %s %s %s %s\n",PID2,fname2,lname2,age2,gender2,contact2);//data get update 
                else 
                fprintf(file1,"%s %s %s %s %s %s\n",PID3[c],firstname[c],lastname[c],age3[c],gender3[c],contact3[c]);//data before and after data update being print in the patients_data.txt
            }
             fclose(file1);
             printf("\nUpdated successfully!\n");//tell user information update successfully
        }
        else     
       printf("Patient ID not found!\n");//tell user patient not found 
}
//Update patient end





// Schedule Appointment start
void ScheduleAppointment()
{
    char AID[10], PID[10], Date[15], Time[10], Doc_name[50];
    char temp_Date[15], temp_Time[10], temp_Doc[50];
    int conflict; //declare variable used 
    FILE *file2;

    do {
        conflict = 0;
        //enter schedule information
        printf("\n=== Schedule Appointment ===\n");
        printf("Appointment ID (A1001): "); scanf("%s", AID);
        printf("Patient ID (P001): "); scanf("%s", PID);
        printf("Date (YYYY-MM-DD,): "); scanf("%s", Date);
        printf("Time (e.g. 10:00AM,): "); scanf("%s", Time);
        printf("Doctor's Name (e.g. James): "); scanf("%s", Doc_name);

        //find if date,time and doctor is the same to prevent double booking 
        file2 = fopen("appointments.txt", "r");
        while (!feof(file2)) {
            if (fscanf(file2, "%s %s Dr. %s", temp_Date, temp_Time, temp_Doc) == 3) {
                if (strcmp(temp_Date, Date) == 0 && 
                    strcmp(temp_Time, Time) == 0 && 
                    strcmp(temp_Doc, Doc_name) == 0) 
                {
                    printf("\nTime slot is already booked. Try a different one.\n");
                    conflict = 1;
                    break;
                }
            }
        } 
        fclose(file2);
    } while (conflict);//program will loop until user didnt input data that is the same 

    //write booking information in appointments.txt
    file2 = fopen("appointments.txt", "a");
    fprintf(file2, "%s, %s, %s %s Dr. %s\n", AID, PID, Date, Time, Doc_name);
    fclose(file2);
    printf("\nAppointment successfully scheduled!\n\n");
}
// Schedule Appointment End






// Record Visit Start
void VisitRecord()
{
    char VID[10],VID2[10],PID[10], date[11], symptoms[100], diagnosis[100], medication[100];
    int conflict;//declare variable used
    FILE *f3 = fopen("visit_records.txt", "a");
    fclose(f3);
    do{
        //enter information for visit record
        conflict=0;
        printf("\n=== Visit Record ===\n");
        printf("Visit ID: "); scanf("%s", VID2);
        printf("Patient ID: "); scanf("%s", PID);
        printf("Date (YYYY-MM-DD): "); scanf("%s", date);
        printf("Symptoms: "); scanf("%s", symptoms);
        printf("Diagnosis: "); scanf("%s", diagnosis);
        printf("Medication: "); scanf("%s", medication);
        f3=fopen("visit_records.txt","r");
        
        //find if any same visit id 
        while(!feof(f3))
        {
            fscanf(f3,"%s",VID);
            if (strcmp(VID2,VID)==0)
            {
                printf("Visit ID has been used. Please try again!\n");
                conflict=1;
                break;
            }
        }
    }
    while (conflict!=0);//program will loop until user won't input the same visit id 
    fclose(f3);
    
    //copy information of visit record in visit_records.txt
    f3=fopen("visit_records.txt","a");
    strcpy(VID,VID2);
    fprintf(f3, "%s, %s, %s, %s, %s, %s\n", VID, PID, date, symptoms, diagnosis, medication);
    fclose(f3);
    printf("\nVisit recorded successfully!\n\n");// tell user data successfully being record
}
//Record Visit End






// Search Menu Start
void Search()
{
    int option;//declare variable
    do {
        printf("\n=== Search Records ===\n");
        printf("1. Patient\n2. Appointments\n3. Visit History\n4. Return\n>> ");//let user so see what selection to choose
        scanf("%d", &option);
        switch (option) {
            case 1: patient(); break;//let user search for patient
            case 2: appointment(); break;//let user search for appointments
            case 3: history(); break;//let user search visit history
            case 4: printf("Returning to main menu...\n\n"); break;//let user return to main menu
            default: printf("Invalid option. Try again.\n"); break;//tell user to try again
        }
    } while (option != 4);//while option is 4 return
}
//Search Menu End





// Search Patient Start
void patient()
{
    FILE *file = fopen("patients_data.txt", "r");   //read patients_data.txt file
    char id[10], fname[20], lname[20], age[10], gender[10], contact[20];
    char search[20];
    int found = 0;//declare variable

    printf("Enter Patient ID or Last Name(e.g. P001, or Smith,): ");//let user search by Patient ID or Last name
    scanf("%s", search);

    while (!feof(file)) {
        if (fscanf(file, "%s %s %s %s %s %s", id, fname, lname, age, gender, contact) == 6) {   //to ensure 6 variable is read
            if (strcmp(id, search) == 0 || 
                strcmp(lname, search) == 0) 
            {
                printf("\n==Patient Found==\n");    //let user know patient is found
                printf("ID: %s First Name: %s Last Name: %s Age: %s Gender: %s Contact: %s\n\n",id, fname, lname, age, gender, contact);
                found = 1;
            }
        }
    }
    if (!found) printf("\nPatient not found!\n");   //let user know patient isn't found
    fclose(file);
}
// Search Patient End




// Search Appointment by Date Start
void appointment()
{
    FILE *file = fopen("appointments.txt", "r");    //read appointments.txt file
    char AID[10], PID[10], Date[15], Time[10], Doc[50], search[15];
    int found = 0;//declare variable

    printf("Enter date (YYYY-MM-DD,): ");   //alow user search by date
    scanf("%s", search);

    while (!feof(file)) {
        if (fscanf(file, "%s %s %s %s Dr. %s", AID, PID, Date, Time, Doc) == 5) {   //ensure 5 variable is read
            if (strcmp(Date, search) == 0) { //if date and search is same
                printf("\n==Appointment Found==\n");    //let user know Appointment found
                printf("Appointment ID: %s Patient ID: %s Date: %s Time: %s Doctor: Dr. %s\n\n",AID, PID, Date, Time, Doc);
                found = 1;
            }
        }
    }
    if (!found) printf("\nAppointment not found!\n");   //let user know Appointment not found
    fclose(file);
}
//Search Appointment End





// Search Visit History Start
void history()
{
    FILE *file = fopen("visit_records.txt", "r");   //read visit_records.txt file
    char VID[10], PID[10], date[11], symptoms[100], diagnosis[100], medication[100];
    char search[10];
    int found = 1;//declare variable

    printf("Enter Patient ID (P001,): ");   //let user search using Patient ID
    scanf("%s", search);

    while (!feof(file)) {
        if (fscanf(file, "%s %s %s %s %s %s", VID, PID, date, symptoms, diagnosis, medication) == 6)    //ensure six variable is read
        {
            if (strcmp(PID, search) == 0)   //if Patient ID and search is the same
            {
                if (found) 
                printf("\n==Visit Records==\n");
                printf("Visit ID: %s Date: %s Symptoms: %s Diagnosis: %s Medication: %s \n\n",VID, date, symptoms, diagnosis, medication);
                found = 0;
            }
        }
    }
    if (found) printf("\nNo visit records found!\n");
    fclose(file);
}
//Search Visit History End
