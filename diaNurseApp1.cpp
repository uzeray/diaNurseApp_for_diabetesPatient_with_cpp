    #include<iostream>
    #include<iomanip>
	#include<limits.h>
using namespace std;

void warning(){

    cout<<"*Please Check to All Numbers before Enter"<<endl<<endl;

    cout<<"*Please Enter Personal Informations all The Correct"<<endl<<endl;

    cout<<"*Please Enter Minimum 5 Days Results"<<endl<<endl;

    cout<<"*This Application can't Give to Exactly Results, Person Must Talk with Doctor for Compare to Application Results"<<endl<<endl<<endl;
    }

 double bmi(double a, double b) {
    double result;
    result = a / (b * b);
    return result;

    }



double insAdvice(double a){

    double tdiAdvice;
    tdiAdvice = 0.55 * a;
    return tdiAdvice;

    }


int main() {
   warning();
   	
	
    int kg, age, gender, lenghtCm, dayNumbers, checkNumbers;

    double carb, carbSum, midCarb, checkSum, midGlukose, gRatesSum;
	double glukoseRates, midLInsDose = 0;
	double midRInsDose = 0, rInsDose, rInsSum, lInsSum, lInsDose, ha1c;
	double bmiRes, coverDose, tdiInsAdv, LInsAdv, lenght, bmrCal = 0;
	double homaIr, value2, cFactor, hGlukose, hInsDose;
	double fatAdv, protAdv, carbAdv, carbRew;

    string fullName;


    cout<<"Enter to Full Name"<<endl;
   getline (cin,fullName);
cout<<endl;
    cout<<"Enter Age"<<endl;
    cin>>age;
cout<<endl;
    cout<<"Enter Weight"<<endl;
    cin>>kg;
cout<<endl;
    cout<<"Enter Length *ex. 1.79"<<endl;
    cin>>lenght;
    lenghtCm = lenght * 100;

    bmiRes = bmi(kg, lenght);

    cout<<"****Prefer to Gender****"<<endl;
    cout<<"1."<<" "<< "female"<<endl;
    cout<<"2."<<" "<<"Male"<<endl;
    cin>>gender;
    switch (gender) {
        case 1: bmrCal = 655.1 + (9.563 * kg) + (1.85 * lenghtCm) - (4.676 * age); break;
        case 2: bmrCal = 66.47 + (13.75 * kg) + (5.003 * lenghtCm) - (6.755 * age); break;
        default: cout<<" NO DATA ";

        }

    carbAdv = (bmrCal / 100) * 30;
    protAdv = (bmrCal / 100) * 40;
    fatAdv = (bmrCal / 100) * 30;


cout<<endl;
    cout<<"How Many Days Followed to Numbers? 4...10 days "<<endl;
    cin>>dayNumbers;

    if(dayNumbers >= 4 && dayNumbers <= 10){

cout<<endl;
    cout<<"Enter Long Acting Insulin Dose"<<endl<<endl;

    for (int i1 = 1; i1<=dayNumbers; i1++) {
        cout<<i1<<". Night Dose"<<endl<<endl;
        cin>>lInsDose;
     lInsSum = lInsDose + lInsSum;
        }
    midLInsDose = lInsSum / dayNumbers;



        cout<<endl;
        cout<<"Enter Rapid Acting Insulin Dose"<<endl;
        for(int i2 = 1; i2 <= dayNumbers; i2++) {
        cout<<i2<<". Day Rapid Insulin Total Dose *IU/ml"<<endl<<endl;
        cin>>rInsDose;
        rInsSum = rInsSum + rInsDose;

        }

        midRInsDose = rInsSum / dayNumbers;


cout<<endl;
        cout<<"How Many Times Checked Glucose Rates per Day? 3...7 times "<<endl;
        cin>>checkNumbers;

        if(checkNumbers >= 3 && checkNumbers <= 7){

        checkSum = dayNumbers * checkNumbers;

cout<<endl;
        cout<<"Enter Every Single Glucose Value"<<endl;

        for(int i3 = 1; i3 <= checkSum; i3++) {
            cout<<i3<<". Value *mg/dl"<<endl<<endl;
            cin>>glukoseRates;
            gRatesSum = gRatesSum + glukoseRates;

            }
        midGlukose = gRatesSum / checkSum;


            value2 = midGlukose / 18.02;


            cout<<"Enter Dailly Carb Value Per Day"<<endl;
            for(int i4 = 1; i4 <= dayNumbers; i4++) {
                cout<<i4<<". Day Total Carb *grams/day"<<endl<<endl;
                cin>>carb;
                carbSum = carbSum + carb;
                }
            midCarb = carbSum / dayNumbers;




            tdiInsAdv = insAdvice(kg);
            LInsAdv = tdiInsAdv / 2;
            coverDose = 500 / tdiInsAdv;
            cFactor = 1800 / tdiInsAdv;
cout<<endl;
            cout<<"Fasting Glucose Rate *mg/dl *minimum after 8 hr. Fasting"<<endl;
            cin>>hGlukose;

cout<<endl;
            cout<<"Fasting Insulin Dose *IU/ml"<<endl;
            cin>>hInsDose;

            homaIr = hGlukose * hInsDose / 405;

        }
        else{
        	cout<<"Enter between 3 and 7, Try Again"<<endl;
        }


cout<<endl;


            cout<<"Last Ha1c Rate *Percent *ex. %8"<<endl;
            cin>>ha1c;

    }

    else {
    	cout<<"invalid value"<<" try from 4 to 10"<<endl;
    }

cout<<endl<<endl;
    cout<<"*****Results*****"<<endl<<endl;

        cout<<"Name : "<<fullName<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Avarage Rapid Acting Insulin Dose :"<<" "<<midRInsDose<<endl;
        cout<<"Avarage Long Acting Insulin Dose :"<<" "<<midLInsDose<<endl;
        cout<<"BMI :"<<" "<<bmiRes<<endl;
        cout<<"Avarage Glukose Rate :"<<" "<<midGlukose<<" mg/dl"<<" "<<float(value2)<<" mmol/dl"<<endl;
        cout<<"Avarage Carb :"<<" "<<midCarb<<endl;
        cout<<"Homo-IR :"<<" "<<homaIr<<endl<<endl<<endl;


      cout<<"*****Advice Report*****"<<endl<<endl;
      
      if(tdiInsAdv < midRInsDose) { 
	  cout<<"DIANURSE Advice to Less Rapid Acting Insulin"<<endl;
	  }
	  else{
	  	cout<<"DIANURSE Advice to Continue with Same Rapid Acting Insulin Dose";
	  }
	  
         cout<<"DIANURSE Advice to :"<<" "<<tdiInsAdv<<" IU/ml Rapid Insulin Maximum in a Day"<<endl;
        
        if(tdiInsAdv / 2 < midLInsDose) {
		cout<<"DIANURSE Advice to Less Long Acting Insulin"<<endl;
		}
		else{
			cout<<"DIANURSE Advice to Continue Same Long Acting Insulin Dose"<<endl;
		}
		
		cout<<"DIANURSE Advice to :"<<" "<<LInsAdv<<" IU/ml Long Insulin Maximum Per Night"<<endl;
        
		if(homaIr <= 1.0){
        cout<<"HOMA-IR  ;"<<homaIr<<" DIANURSE Advice to Less Insulin have Extra Insulin Sensitivity "<<endl;
        }
    if(homaIr > 1.0 & homaIr <= 1.9){
        cout<<"HOMA-IR  ;"<<homaIr<<" DIANURSE Advice to Stay Good Sensitivity with IR "<<endl;
        }
    else if (homaIr > 1.9 & homaIr < 2.5){
        cout<<"HOMA-IR  ;"<<homaIr<<" DIANURSE Advice to Diet Specialist for Possible have Insulin Resistance"<<endl;
        }
        else {
            cout<<"HOMA-IR  ;"<<homaIr<<"  DIANURSE Advice to Diabetes and Diet Specialist for High Insulin Resistance "<<endl;
            }

        cout<<"DIANURSE Advice to 1 IU/ml Rapid Acting Insulin per :"<<coverDose<<" gr. of Carbonhydrate"<<endl;
        cout<<"DIANURSE Advice to 1 IU/ml Rapid Acting Insulin :"<<cFactor<<" mg/dl"<<" "<<cFactor / 18.02<<" mmol/dl  "<<"can make Correction"<<endl;
        cout<<"DIANURSE Advice to Minimum Dailly Calories ;"<<bmrCal<<"  kcal minimum in a Day"<<endl;
        cout<<"DIANURSE Advice to %40 of Total Calories "<<protAdv / 4<<" gr. Protein in a Day"<<endl;
        cout<<"DIANURSE Advice to %30 of Total Calories "<<carbAdv / 4<<" gr.Carbonhydrate in a Day"<<endl;
        cout<<"DIANURSE Advice to %30 of Total Calories "<<fatAdv / 9<<" gr. Fat in a Day"<<endl;

        if(bmiRes < 18.0) {
        	cout<<"DIANURSE Advice to Gain Weight"<<bmrCal + 650<<" kcal in a Day"<<endl;
        }
        else if(bmiRes > 24.0){
        	cout<<"DIANURSE Advice to Lose Weight Maximum "<<bmrCal + 150<<" kcal in a Day"<<endl;
        }
        else{
        	cout<<"DIANURSE Advice to Save to ideal Body Weight with "<<bmrCal + 325<<" kcal in a Day"<<endl;
        }
        cout<<"DIANURSE Advice to %30 more Rapid Acting Insulin for 90 gr Protein"<<endl;
		        
		
		if(ha1c >= 4.9 && ha1c<=6.7 ){
			cout<<"DIANURSE Advice to Continue to Healthy Rate of Hemoglobin A1C"<<endl;
		}
		else if(ha1c > 6.7 && ha1c <= 7.5){
			cout<<"DIANURSE Advice to Change Insulin Doses Hemoglobin A1C is in Border"<<endl;
		}
		else{
			cout<<"DIANURSE Advice to Specialist Appointment Hemoglobin A1C is Dengerous Area"<<endl;
		}




return 0;}


