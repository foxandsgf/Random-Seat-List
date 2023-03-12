#include <bits/stdc++.h>
using namespace std;
int seat_list[30];
vector<int> rest_mate_list,rest_seat_list;
vector<string> old_mate_num;
map<string,string> deskmate,namechange;

inline void init1(){
	ifstream nl;
	nl.open("namelist.txt");
	string name,fname;
	while(!nl.eof()){
		nl>>fname;
		nl>>name;
		namechange[fname]=name;
	}
	nl.close();
	cout<<"<<DONE INIT>>"<<endl;
}

inline void init2(){
	rest_mate_list.clear();
	rest_seat_list.clear();
	for(int i=0;i<25;i++){
		seat_list[i]=0;
		rest_mate_list.push_back(i);
		rest_seat_list.push_back(i);
	}
}

inline void readlist()
{
	ifstream nl("Random list[FN].csv");
	string t;
	char name1[5]=" ",name2[5]=" ";
	memset(name1,'\0',sizeof(name1));
	memset(name2,'\0',sizeof(name2));
	vector<string> name;
	
	while(!nl.eof()){
		nl>>t;
		int it=0,it1=0,it2=0,first=1;
		for(int i=0;i<=t.size();i++){
			char temp=t[it++];
			if(temp==','||i==t.size()){
				it1=0;
				it2=0;
				if(first) first=0;
				else{
					first=1;
					if(name1[0]=='\0') continue;
					old_mate_num.push_back(name1);
					deskmate[name1]=name2;
					memset(name1,'\0',sizeof(name1));
					memset(name2,'\0',sizeof(name2));
				}
				continue;
			}
			if(first){
				name1[it1++]=temp;
				continue;
			}
			else{
				name2[it2++]=temp;
				continue;
			}
		}
	}
	nl.close();
	cout<<"<<READLIST DONE>>"<<endl;
}

inline void writelist_EN(){
	ofstream nl;
	nl.open("Random list[FN].csv");
	while(nl.fail()){
		cout<<"Fail to write [FN]version"<<endl;
		cout<<"Close All windows"<<endl;
		system("pause");
		cout<<"Type command 'RWF' and Try again"<<endl;
		return;
	}
	string temp1=old_mate_num[seat_list[0]],temp2=old_mate_num[seat_list[1]];
	string temp3=old_mate_num[seat_list[4]],temp4;
	nl<<",,"<<temp1<<","<<deskmate[temp1]<<","<<temp2<<","<<deskmate[temp2]<<endl;
	temp1=old_mate_num[seat_list[2]];
	temp2=old_mate_num[seat_list[3]];
	nl<<",,"<<temp1<<","<<deskmate[temp1]<<","<<temp2<<","<<deskmate[temp2]<<",";
	nl<<temp3<<","<<deskmate[temp3]<<endl;
	int it=5;
	for(int i=1;i<=5;i++){
		temp1=old_mate_num[seat_list[it++]];
		temp2=old_mate_num[seat_list[it++]];
		temp3=old_mate_num[seat_list[it++]];
		temp4=old_mate_num[seat_list[it++]];
		nl<<temp1<<","<<deskmate[temp1]<<","<<temp2<<","<<deskmate[temp2]<<",";
		nl<<temp3<<","<<deskmate[temp3]<<","<<temp4<<","<<deskmate[temp4]<<endl;
	}
	nl.close();
	cout<<"<<FN WRITING DONE>>"<<endl;
}

inline void writelist_CN(){
	ofstream nl;
	nl.open("Random list[CN].csv");
	while(nl.fail()){
		cout<<"Fail to write [CN]version"<<endl;
		cout<<"Close All windows"<<endl;
		system("pause");
		cout<<"Type command 'RWC' and Try again"<<endl;
		return;
	}
	string temp1=old_mate_num[seat_list[0]],temp2=old_mate_num[seat_list[1]];
	string temp3=old_mate_num[seat_list[4]],temp4;
	nl<<",,"<<namechange[temp1]<<","<<namechange[deskmate[temp1]]<<","<<namechange[temp2]<<","<<namechange[deskmate[temp2]]<<endl;
	temp1=old_mate_num[seat_list[2]];
	temp2=old_mate_num[seat_list[3]];
	nl<<",,"<<namechange[temp1]<<","<<namechange[deskmate[temp1]]<<","<<namechange[temp2]<<","<<namechange[deskmate[temp2]]<<",";
	nl<<namechange[temp3]<<","<<namechange[deskmate[temp3]]<<endl;
	int it=5;
	for(int i=1;i<=5;i++){
		temp1=old_mate_num[seat_list[it++]];
		temp2=old_mate_num[seat_list[it++]];
		temp3=old_mate_num[seat_list[it++]];
		temp4=old_mate_num[seat_list[it++]];
		nl<<namechange[temp1]<<","<<namechange[deskmate[temp1]]<<","<<namechange[temp2]<<","<<namechange[deskmate[temp2]]<<",";
		nl<<namechange[temp3]<<","<<namechange[deskmate[temp3]]<<","<<namechange[temp4]<<","<<namechange[deskmate[temp4]]<<endl;
	}
	nl.close();
	cout<<"<<CN WRITING DONE>>"<<endl;
}

inline void work_ra(){
	int a=25;
	while(a){
		int random_mate=rand()%a;
		int random_seat=rand()%a;
		int name_num=rest_mate_list[random_mate];
		int seat_num=rest_seat_list[random_seat];
		rest_mate_list.erase(rest_mate_list.begin()+random_mate);
		rest_seat_list.erase(rest_seat_list.begin()+random_seat);
		seat_list[seat_num]=name_num; //同学name_num现到seat_num上 
		a--;
	}
	cout<<"<<FUNCTION DONE>>"<<endl;
	writelist_EN();
	writelist_CN();
}

inline void console(){
	cout<<"Type command:";
	string comm;
	cin>>comm;
	while(1){
		if(comm.compare("exit")==0||comm.compare("quit")==0) return;
		if(comm.compare("test")==0){
			int ques;
			cin>>ques;
			switch(ques){
				case 1:{
					string l;
					cin>>l;
					cout<<deskmate[l]<<endl;
					break;
				}
				case 2:{
					int l;
					cin>>l;
					cout<<old_mate_num[l]<<endl;
					break;
				}
			}
			cin>>comm;
			continue;
		}
		if(comm.compare("RWF")==0){
			writelist_EN();
			cin>>comm;
			continue;
		}
		if(comm.compare("RWC")==0){
			writelist_CN();
			cin>>comm;
			continue;
		}
		if(comm.compare("do")==0){
			init2();
			work_ra();
			cin>>comm;
			continue;
		}
		if(comm.compare("help")==0){
			cout<<"COMMAND LIST:"<<endl;
			cout<<"1.'do' - work the function"<<endl;
			cout<<"2.'RWF' - Write FN list again after Error";
			cout<<"3.'RWC' - Write CN list again after Error";
			cout<<"4.'exit' - close the program"<<endl;
			cout<<"Use method:"<<endl;
			cout<<"1.Rename Oringinal File \"Oringinal.csv\""<<endl;
			cout<<"2.Put the file at as the same path as the process"<<endl;
			cout<<"3.Type command \"do\""<<endl;
			cout<<"4.Get random list named \"Random list[$version$].csv\""<<endl;
			cout<<"5.Type command \"exit\" to close the process"<<endl;
			cin>>comm;
		}
		else{
			cout<<"WRONG COMMAND"<<endl;
			cout<<"You can type 'help' to get command"<<endl;
			cin>>comm;
		}
	}
}

int main(){
	init1();
	init2();
	readlist();
	console();
	return 0;
}