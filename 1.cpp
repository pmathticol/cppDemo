#include<iostream>
#include<map>
#include<exception>
#include<string>
#include<iterator>
using namespace std;

class Date{
	
	public:
	int year,month,day;
	Date(int y,int m,int d){
		this->year=y;
		this->month=m;
		this->day=d;
	}
	
	bool checkIfVaildDate(Date &d){
		
		cout<<"year="<<d.year<<"month="<<d.month<<"Day="<<d.day<<endl;  
		if(d.month<1||d.month>12){
			//throw new exception();
			return false;
		}
		if(d.year%4==0||(d.year%100!=0&&d.year%400==0)){
			//闰年的情况
			 if(d.month==2&&d.day>29){
			 	//throw new exception(); 
			 		return false;
			 } 
		}else{
			//平年的情况 
			if(d.month==2&&d.day>28){
			 	//throw new exception(); 
			 		return false;
			 }
		}
		
		if(d.month==1||d.month==3||d.month==5||d.month==7||d.month==8||d.month==10||d.month==12){
			if(d.day>31){
			 	//throw new exception(); 	
			 		return false;
			}
		}
		else if(d.month==4||d.month==6||d.month==9||d.month==11){
			if(d.day>30){
			 	//throw new exception(); 
				 	return false;	
			}
		}
		
		return true;
	}
	
	
	int calculateDayOfCurYear(Date date){
	int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int num=0;
	//Date date=Date(date.year,1,1);
	for(int m=1;m<date.month;m++){
		num+=day[m];
	}
	
	for(int d=1;d<=date.day;d++){
		num+=1;
	} 
	return num;
    }
};



int getIntFromStr(string str){
	if(str==""){
	  return -1;	
	}
	int num=0;
	int len=str.length();
	for(int i=0;i<len;i++){
		num=num*10+str[i]-'0';
	}
	return num;
}
Date parseDateFromString(string str){
    
	string _sYear=str.substr(0,4);
	string _sMonth=str.substr(5,2);
	string _sDay=str.substr(8,2);
	cout<<"year="<<_sYear<<"month="<<_sMonth<<"Day="<<_sDay<<endl;  
	Date date=Date(getIntFromStr(_sYear),getIntFromStr(_sMonth),getIntFromStr(_sDay));
	cout<<"year="<<date.year<<"month="<<date.month<<"Day="<<date.day<<endl;  
	return date;
}




int main()
{	
	while(1){
	cout<<"请输入日期：（格式：年月日，如2016-01-06\n) (---输入End，退出---\n)";
	string str;
	cin>>str;
	
	if(str=="End"){
		break;
	}
	
	int day;
//	try{
	Date date=parseDateFromString(str);
	if(date.checkIfVaildDate(date)){
	day=date.calculateDayOfCurYear(date);	
	}else{
	  cout<<"日期格式不正确，程序终止";
	  continue ; 
	}
  //  }
//	catch(exception &e){
//      cout<<"日期格式不正确，程序终止";
//	  continue ; 
//	}
	if(day==-1){
	   cout<<"你输入的日期格式不对，请重新输入"<<endl;
	} else{
	   cout<<str<<"为该年的第 "<<day<<" 天"<<endl; 
	}
	
    }
    
    return 0;
}
