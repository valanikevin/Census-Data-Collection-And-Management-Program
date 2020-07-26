/*
Name: Kevin Valani
Program: Census Management System.
Date: June 22, 2020.
Revision: June 21, June 22.
Code Working: 1) CLI based functionality.
              2) At every option selected, a dedicated method call is made.
              3) Each mehthod is updating one central array of size 100;
              4) Two ways to fill array, Manual and Random.
Built On: XCode. OS: MacOS.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//A Structure of Human Record.
struct humanRecord{
    char regionName[50];
    char cityName[50];
    char humRace[50];
    int housePeople;
    double annualIncome;
};

//Below are the values which is never changed in the program later.
const char *allRegion[3] = {"Durham", "Peel", "York"};
const char *allCity[6] = {"Whitby", "Oshawa", "Brampton", "Mississauga", "Maple", "Vaughan"};
const char *allRace[5] = {"Caucasian", "Indigenous", "African American", "Asian", "Other"};

//Method Prototype.
void startMenu(void);
void mainMenu(void);
void overallAverage(void);
void houByRegion(void);
void houByRace(void);
void avgByTownAndCity(void);
void avgByRace(void);
void perOverall(void);
void perByRegionAndTown(void);
void perByRace(void);
bool checkProverty(int);
void addRandom(void);
void addManual(void);
const char* selectRegion(bool);
//Prototype is defined as per need.


//printf("\n");
struct humanRecord hRecord[100];
int recCount = 0;

//Based on user input, will return appropriate Region.
const char* selectRegion(bool random){
    if(random==false){
        printf("Please Enter Region Number\n");
        printf("1. Durham\n2. Peel\n3. York\n4. Generate Rest Randomly.\n5. Skip or Go To Main Menu.\n6. Exit.\n");
        int uIN = 0;
        scanf("%d", &uIN);
        if(uIN==1){
            return allRegion[0];
        }
        else if(uIN==2){
            return allRegion[1];
        }
        else if(uIN==3){
            return allRegion[2];
        }
        else if(uIN==4){
            addRandom();
        }
        else if(uIN==5){
            mainMenu();
        }
        else if(uIN==6){
            exit(0);
        }
        else{
            printf("Incorrect Entry: Please Try Again.\n");
            selectRegion(false);
        }
    }
    else{
        return allRegion[(rand()%(2-0+1))+0];
    }
    return "";
}

//Based on user input, will return appropriate City.
const char* selectCity(char* regName, bool random){
    if(random==false){
        printf("Please Enter City Number\n");
        int uIN = 0;
        if(strcmp(regName, "Durham")==0){
            printf("1. Oshawa\n2. Whitby\n");
        }
        else if(strcmp(regName, "Peel")==0){
            printf("3. Brampton\n4. Mississauga\n ");
        }
        else if(strcmp(regName, "York")==0){
            printf("4. Maple\n 6. Vaughan\n");
        }
        printf("7. Exit.");
        scanf("%d", &uIN);
        if(uIN==1){
            return allCity[0];
        }
        else if(uIN==2){
            return allCity[1];
        }
        else if(uIN==3){
            return allCity[2];
        }
        else if(uIN==4){
            return allCity[3];
        }
        else if(uIN==5){
            return allCity[4];
        }
        else if(uIN==6){
            return allCity[5];
        }
        else if(uIN==7){
            exit(0);
        }
        else{
            printf("Incorrect Entry: Please Try Again.\n");
            selectCity(regName, false);
        }
        
    }
    else{
        
        int uIN = 0;
        if(strcmp(regName, "Durham")==0){
            if(recCount%2==0){
                uIN = 1;
            }
            else{
                uIN = 2;
            }
        }
        else if(strcmp(regName, "Peel")==0){
            if(recCount%2==0){
                uIN = 3;
            }
            else{
                uIN = 4;
            }
        }
        else if(strcmp(regName, "York")==0){
            if(recCount%2==0){
                uIN = 5;
            }
            else{
                uIN = 6;
            }
        }
        
        if(uIN==1){
            return allCity[0];
        }
        else if(uIN==2){
            return allCity[1];
        }
        else if(uIN==3){
            return allCity[2];
        }
        else if(uIN==4){
            return allCity[3];
        }
        else if(uIN==5){
            return allCity[4];
        }
        else if(uIN==6){
            return allCity[5];
        }
        else if(uIN==7){
            exit(0);
        }
    }
    return "L";
}

//Based on user input, will return appropriate Race.
const char* selectRace(bool random){
    
    if(random==false){
        printf("Please Enter Race Number\n");
        printf("1. Caucasian\n2. Indigenous\n3. Africian American\n4. Asian\n5. Other\n6. Exit\n");
        int uIN = 0;
        scanf("%d", &uIN);
        if(uIN==1){
            return allRace[0];
        }
        else if(uIN==2){
            return allRace[1];
        }
        else if(uIN==3){
            return allRace[2];
        }
        else if(uIN==4){
            return allRace[3];
        }
        else if(uIN==5){
            return allRace[4];
        }
        else if(uIN==6){
            exit(0);
        }
        else{
            printf("Incorrect Entry: Please Try Again.\n");
            selectRace(false);
        }
    }
    else{
        return allRace[(rand()%(4-0+1))+0];
    }
    return "";
}

//Based on user input, will return appropriate Households.
int selectTotalHouseHold(bool random){
    if(random==false){
        printf("Enter Total Number Of Household: ");
        int tHouseHold = 0;
        scanf("%d", &tHouseHold);
        if(tHouseHold<1){
            printf("Incorrent Entry: Please Try Again.\n");
            selectTotalHouseHold(false);
        }
        else{
            return tHouseHold;
        }
    }
    else{
        return (rand()%(10-2+1))+2;
    }
    return 0;
}

//Based on user input, will return appropriate Income.
double selectTotalHouHolIncome(bool random){
    double tHouseHold = 0;
    if(random==false){
        printf("Enter Combined Household Income: ");
        
        scanf("%lf", &tHouseHold);
        if(tHouseHold<0){
            printf("Incorrent Entry: Please Try Again.");
            selectTotalHouHolIncome(false);
        }
        else{
            return tHouseHold;
        }
    }
    else{
        return (rand()%(200000-10000+1))+10000;
    }
    
    return tHouseHold;
}

//Method to add random entries from the last added entry to 100th place.
void addRandom(){
    for(int i=recCount; i<100; i++){
        const char* regName = selectRegion(true);
        const char* cityName = selectCity(regName, true);
        const char* raceType = selectRace(true);
        int tHouHolds = selectTotalHouseHold(true);
        double tHouIncome = selectTotalHouHolIncome(true);
        
        strcpy(hRecord[recCount].regionName, regName);
        strcpy(hRecord[recCount].cityName, cityName);
        strcpy(hRecord[recCount].humRace, raceType);
        hRecord[recCount].annualIncome = tHouIncome;
        hRecord[recCount].housePeople = tHouHolds;
        recCount++;
    }
    printf("**************************************\n");
    printf("Data: Random Data Was Added Successfully.\n");
    printf("**************************************\n");
    mainMenu();
}

//Method to add manual data entry.
void addManual(){
    
    for(int i=recCount; i<5; i++){
        printf("--------------------------------------\n");
        printf("Add Entry: Number %d\n", recCount);
        printf("--------------------------------------\n");
        
        const char* regName = selectRegion(false);
        const char* cityName = selectCity(regName, false);
        const char* raceType = selectRace(false);
        int tHouHolds = selectTotalHouseHold(false);
        double tHouIncome = selectTotalHouHolIncome(false);
        
        strcpy(hRecord[recCount].regionName, regName);
        strcpy(hRecord[recCount].cityName, cityName);
        strcpy(hRecord[recCount].humRace, raceType);
        hRecord[recCount].annualIncome = tHouIncome;
        hRecord[recCount].housePeople = tHouHolds;
        recCount++;
    }
    
    mainMenu();
}

//Start Menu, to be displayed at start of the program.

void startMenu(){
    printf("**************************************\n");
    printf("Menu: Start Menu\n");
    printf("**************************************\n");
    printf("Please Select Appropriate Option: \n");
    if(recCount<6){
        printf("1. Add 5 Users Manually.\n");
    }
    printf("2. Add Users Randomly.\n");
    printf("3. Go To Main Menu.\n");
    printf("4. Exit.\n");
    int uIN = 0;
    scanf("%d", &uIN);
    if(uIN == 1){
        for(int i=0; i<2; i++){
           addManual();
        }
        
    }
    else if(uIN == 2){
        for(int i=recCount; i<100; i++){
            addRandom();
            mainMenu();
        }
    }
    else if(uIN == 3){
        mainMenu();
    }
    else if(uIN ==4){
        exit(0);
    }
    else{
        printf("Invalid Input: Please try again.");
        startMenu();
    }
}

//Print all data is nice formatted manner.
void viewAllData(){
    printf("**************************************\n");
    printf("Data: View All Data\n");
    printf("**************************************\n");
    //printf("Number\t\tIncome\t\tHouse Holds\t\tRace\t\t\tRegion\tCity\n");
    printf("%-10s%-20s%-20s%-20s%-20s%-20s\n", "Number", "Income", "House Holds", "Race", "Region", "City");
    for(int i=0; i<recCount; i++){
        //printf("%d\t\t%.2lf\t\t%d\t\t%s\t%s\t%s\n", (i+1), hRecord[i].annualIncome, hRecord[i].housePeople, hRecord[i].humRace, hRecord[i].regionName, hRecord[i].cityName);
        printf("%-10d%-20.2lf%-20d%-20s%-20s%-20s\n",(i+1), hRecord[i].annualIncome, hRecord[i].housePeople, hRecord[i].humRace, hRecord[i].regionName, hRecord[i].cityName);
        
    }
    printf("\n");
    mainMenu();
}

//Main menu - Typically used after data is filled.
void mainMenu(){
    printf("**************************************\n");
    printf("Menu: Main Menu\n");
    printf("**************************************\n");
    printf("Please Select Appropriate Option: \n");
    printf("1. Go To Start Menu\n");
    printf("2. View All Data.\n");
    printf("3. Household Count By Region.\n");
    printf("4. Household Count By Race.\n");
    printf("5. Average: Overall.\n");
    printf("6. Average: By Region & Town.\n");
    printf("7. Average: By Race.\n");
    printf("8. Poverty: Overall Percentage\n");
    printf("9. Poverty: Percentage By Race\n");
    printf("10. Poverty: Percentage By Region & City.\n");
    printf("11. Exit.\n");
    int uIN = 0;
    scanf("%d", &uIN);
    if(uIN == 1){
        startMenu();
    }
    else if(uIN == 2){
        viewAllData();
    }
    else if(uIN == 3){
        houByRegion();
    }
    else if(uIN ==4){
        houByRace();
    }
    else if(uIN ==5){
        overallAverage();
    }
    else if(uIN ==6){
        avgByTownAndCity();
    }
    else if(uIN ==7){
        avgByRace();
    }
    else if(uIN ==8){
        perOverall();
    }
    else if(uIN ==9){
        perByRace();
    }
    else if(uIN ==10){
        perByRegionAndTown();
    }
    else if(uIN ==11){
        exit(0);
    }
    else{
        printf("Invalid Input: Please try again.");
        startMenu();
    }
}

//Displays overall Average.
void overallAverage(){
    double houIncome = 0;
    double houHolds = 0;
    for(int i=0; i< recCount; i++){
        houIncome+=hRecord[i].annualIncome;
        houHolds+=hRecord[i].housePeople;
    }
    printf("**************************************\n");
    printf("Average: Overall\n");
    printf("**************************************\n");
    printf("Average: %.2lf\nTotal People Surveyed: %.2lf\nCombined Income: %.2lf\n", round((houIncome/houHolds)), houHolds, houIncome);
    printf("**************************************\n");
    mainMenu();
}

//Displays Household number by Region
void houByRegion(){
    int regPeel = 0;
    int regYork = 0;
    int regDurham = 0;
    for(int i=0; i<recCount; i++){
        if(strcmp(hRecord[i].regionName, "Durham")==0){
            regDurham++;
        }
        else if(strcmp(hRecord[i].regionName, "York")==0){
            regYork++;
        }
        else if(strcmp(hRecord[i].regionName, "Peel")==0){
            regPeel++;
        }
    }
    printf("**************************************\n");
    printf("House Holds: By Region\n");
    printf("**************************************\n");
    printf("- Durham Region: %d\n- York Region: %d\n- Peel Region: %d\n", regDurham, regYork, regPeel);
    printf("**************************************\n");
    mainMenu();
}

//Displays Household number by Race
void houByRace(){
    int Caucasian = 0;
    int Indigenous = 0;
    int AfricanAmerican = 0;
    int Asian = 0;
    int Other = 0;
    
    for(int i=0; i<recCount;i++){
        if(strcmp(hRecord[i].humRace, "Caucasian")==0){
            Caucasian++;
        }
        else if (strcmp(hRecord[i].humRace, "Indigenous")==0){
            Indigenous++;
        }
        else if (strcmp(hRecord[i].humRace, "African American")==0){
            AfricanAmerican++;
        }
        else if (strcmp(hRecord[i].humRace, "Asian")==0){
            Asian++;
        }
        else if (strcmp(hRecord[i].humRace, "Other")==0){
            Other++;
        }
    }
    
    printf("**************************************\n");
    printf("House Holds: By Race\n");
    printf("**************************************\n");
    printf("- Caucasian: %d\n- Indigenous: %d\n- African American: %d\n- Asian: %d\n- Other: %d\n", Caucasian, Indigenous, AfricanAmerican, Asian, Other);
    printf("**************************************\n");
    
    mainMenu();
}

//Displays Household number by Town and City.
void avgByTownAndCity(){
    double ctOshawa= 0;
    double ctOsIncome = 0;
    double ctWhitby = 0;
    double ctWhIncome = 0;
    double ctMississauga = 0;
    double ctMiIncome = 0;
    double ctBrampton = 0;
    double ctBrIncome = 0;
    double ctMaple = 0;
    double ctMaIncome = 0;
    double ctVaughan = 0;
    double ctVaIncome = 0;
    
    for(int i=0; i<recCount; i++){
        if(strcmp(hRecord[i].cityName, "Oshawa")==0){
            ctOshawa+=hRecord[i].housePeople;
            ctOsIncome+=hRecord[i].annualIncome;
            
        }
        else if(strcmp(hRecord[i].cityName, "Whitby")==0){
            ctWhitby+=hRecord[i].housePeople;
            ctWhIncome+=hRecord[i].annualIncome;
        }
        else if(strcmp(hRecord[i].cityName, "Mississauga")==0){
            ctMississauga+=hRecord[i].housePeople;
            ctMiIncome+=hRecord[i].annualIncome;
        }
        else if(strcmp(hRecord[i].cityName, "Brampton")==0){
            ctBrampton+=hRecord[i].housePeople;
            ctBrIncome+=hRecord[i].annualIncome;
        }
        else if(strcmp(hRecord[i].cityName, "Maple")==0){
            ctMaple+=hRecord[i].housePeople;
            ctMaIncome+=hRecord[i].annualIncome;
        }
        else if(strcmp(hRecord[i].cityName, "Vaughan")==0){
            ctVaughan+=hRecord[i].housePeople;
            ctVaIncome+=hRecord[i].annualIncome;
        }
    }
    printf("**************************************\n");
    printf("Average: Income By Region And Cities\n");
    printf("**************************************\n");
    printf("- Durham Region: \n");
    printf("- \tOshawa: %.2lf \n", round(ctOsIncome/ctOshawa));
    printf("- \tWhitby: %.2lf\n", round(ctWhIncome/ctWhitby));
    printf("- Peel Region: \n");
    printf("- \tMississauga: %.2lf \n", round(ctMiIncome/ctMississauga));
    printf("- \tBrampton: %.2lf\n", round(ctBrIncome/ctBrampton));
    printf("- York Region: \n");
    printf("- \tMaple: %.2lf\n", round(ctMaIncome/ctMaple));
    printf("- \tVaughan: %.2lf\n", round(ctVaIncome/ctVaughan));
    printf("**************************************\n");
    mainMenu();
}

//Displays Average by Race.
void avgByRace(){
    double Caucasian= 0;
    double ctCaucasian = 0;
    double Indigenous = 0;
    double ctIndigenous = 0;
    double AfricanAmerican = 0;
    double ctAfricanAmerican = 0;
    double Asian = 0;
    double ctAsian = 0;
    double Other = 0;
    double ctOther = 0;
    
    for(int i=0; i<recCount; i++){
        if(strcmp(hRecord[i].humRace, "Caucasian")==0){
            Caucasian+=hRecord[i].housePeople;
            ctCaucasian+=hRecord[i].annualIncome;
            
        }
        else if(strcmp(hRecord[i].humRace, "Indigenous")==0){
            Indigenous+=hRecord[i].housePeople;
            ctIndigenous+=hRecord[i].annualIncome;
        }
        else if(strcmp(hRecord[i].humRace, "African American")==0){
            AfricanAmerican+=hRecord[i].housePeople;
            ctAfricanAmerican+=hRecord[i].annualIncome;
        }
        else if(strcmp(hRecord[i].humRace, "Asian")==0){
            Asian+=hRecord[i].housePeople;
            ctAsian+=hRecord[i].annualIncome;
        }
        else if(strcmp(hRecord[i].humRace, "Other")==0){
            Other+=hRecord[i].housePeople;
            ctOther+=hRecord[i].annualIncome;
        }
    }
    printf("**************************************\n");
    printf("Average: Income By Race\n");
    printf("**************************************\n");
    printf("- Caucasian: %.2lf\n", round(ctCaucasian/Caucasian));
    printf("- Indigenous: %.2lf\n", round(ctIndigenous/Indigenous));
    printf("- African American: %.2lf\n", round(ctAfricanAmerican/AfricanAmerican));
    printf("- Asian: %.2lf\n", round(ctAsian/Asian));
    printf("- Other: %.2lf\n", round(ctOther/Other));
    
    printf("**************************************\n");
    mainMenu();
}

//Check For Poverty at specified index of main data array.
bool checkProverty(int index){
    bool status = false;
    
    if(hRecord[index].annualIncome<15000&&hRecord[index].housePeople==1){
        status = true;
    }
    else if(hRecord[index].annualIncome<20000&&hRecord[index].housePeople==2){
        status = true;
    }
    else if(hRecord[index].annualIncome<25000&&hRecord[index].housePeople==3){
        status = true;
    }
    else if(hRecord[index].annualIncome<30000&&hRecord[index].housePeople==4){
        status = true;
    }
    else if(hRecord[index].annualIncome<40000&&hRecord[index].housePeople>=5){
        status = true;
    }
    
    return status;
}

//Displays Percentage of Poverty Overall.
void perOverall(){
    int allHumans = 0;
    int belowPoverty = 0;
    
    for(int i=0; i<recCount; i++){
        allHumans+=hRecord[i].housePeople;
        if(checkProverty(i)){
            belowPoverty++;
        }
    }
    double per = ((double)belowPoverty/(double)allHumans)*100;
    printf("**************************************\n");
    printf("Percentage: Poverty\n");
    printf("**************************************\n");
    printf("Overall Percentage: %.2lf \n", per);
    printf("**************************************\n");
    mainMenu();
}

//Displays Percentage of Poverty By Race.
void perByRace(){
    double Caucasian= 0;
    double ctCaucasian = 0;
    double Indigenous = 0;
    double ctIndigenous = 0;
    double AfricanAmerican = 0;
    double ctAfricanAmerican = 0;
    double Asian = 0;
    double ctAsian = 0;
    double Other = 0;
    double ctOther = 0;
    
    for(int i=0; i<recCount; i++){
        if(strcmp(hRecord[i].humRace, "Caucasian")==0){
            Caucasian+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctCaucasian++;
            }
            
        }
        else if(strcmp(hRecord[i].humRace, "Indigenous")==0){
            Indigenous+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctIndigenous++;
            }
        }
        else if(strcmp(hRecord[i].humRace, "African American")==0){
            AfricanAmerican+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctAfricanAmerican++;
            }
        }
        else if(strcmp(hRecord[i].humRace, "Asian")==0){
            Asian+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctAsian++;
            }
        }
        else if(strcmp(hRecord[i].humRace, "Other")==0){
            Other+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctOther++;
            }
        }
    }
    printf("**************************************\n");
    printf("Percentage: Poverty By Race\n");
    printf("**************************************\n");
    printf("- Caucasian: %.2lf\n", round((ctCaucasian/Caucasian)*100));
    printf("- Indigenous: %.2lf\n", round((ctIndigenous/Indigenous)*100));
    printf("- African American: %.2lf\n", round((ctAfricanAmerican/AfricanAmerican)*100));
    printf("- Asian: %.2lf\n", round((ctAsian/Asian)*100));
    printf("- Other: %.2lf\n", round((ctOther/Other)*100));
    
    printf("**************************************\n");
    mainMenu();
}

//Displays Percentage of Poverty By Town.
void perByRegionAndTown(){
    //Please ignore Variable name meaning.
    int ctOshawa= 0;
    double ctOsIncome = 0;
    int ctWhitby = 0;
    double ctWhIncome = 0;
    int ctMississauga = 0;
    double ctMiIncome = 0;
    int ctBrampton = 0;
    double ctBrIncome = 0;
    int ctMaple = 0;
    double ctMaIncome = 0;
    int ctVaughan = 0;
    double ctVaIncome = 0;
    
    for(int i=0; i<recCount; i++){
        if(strcmp(hRecord[i].cityName, "Oshawa")==0){
            ctOshawa+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctOsIncome++;
            }
            
        }
        if(strcmp(hRecord[i].cityName, "Whitby")==0){
            ctWhitby+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctWhIncome++;
            }
            
        }
        if(strcmp(hRecord[i].cityName, "Mississauga")==0){
            ctMississauga+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctMiIncome++;
            }
            
        }
        if(strcmp(hRecord[i].cityName, "Maple")==0){
            ctMaple+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctMaIncome++;
            }
            
        }
        if(strcmp(hRecord[i].cityName, "Vaughan")==0){
            ctVaughan+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctOsIncome++;
            }
            
        }
        if(strcmp(hRecord[i].cityName, "Brampton")==0){
            ctBrampton+=hRecord[i].housePeople;
            if(checkProverty(i)){
                ctBrIncome++;
            }
            
        }
    }
    printf("**************************************\n");
    printf("Percentage: Percentage By Region And Cities\n");
    printf("**************************************\n");
    printf("- Durham Region: \n");
    printf("- \tOshawa: %.2lf \n", round((ctOsIncome/ctOshawa)*100));
    printf("- \tWhitby: %.2lf\n", round((ctWhIncome/ctWhitby)*100));
    printf("- Peel Region: \n");
    printf("- \tMississauga: %.2lf \n", round((ctMiIncome/ctMississauga)*100));
    printf("- \tBrampton: %.2lf\n", round((ctBrIncome/ctBrampton)*100));
    printf("- York Region: \n");
    printf("- \tMaple: %.2lf\n", round((ctMaIncome/ctMaple)*100));
    printf("- \tVaughan: %.2lf\n", round((ctVaIncome/ctVaughan)*100));
    printf("**************************************\n");
    mainMenu();
}

int main(int argc, const char * argv[]) {
    printf("\n");
    printf("**************************************\n");
    printf("**************************************\n");
    printf("Census Management System\n");
    printf("PLEASE NOTE: This Program is Written On macOS on XCode.\n");
    printf("**************************************\n");
    startMenu();
    
    
    return 0;
}





