#include <iostream>
#include <fstream>
#include<string>
using namespace std;





bool func(string str){
	if(str.size()>1)
		return true;
	return false;


}


//���.txt�ļ����ݵ���Ч�����͵�����
bool Check(string Path){
	//�������·���ĺ�׺�Ƿ�Ϸ�


	size_t index=Path.find_last_of(".");
	string str=Path.substr(index+1);
	if( strcmp(str.c_str(),"txt")==0 )
		return true;
	
	else{
		
		return false;
	}
	


}

int Parse_line(string Path){
	
	size_t count=0;
	ifstream file(Path.c_str());
	if(!file.is_open()){
		cout<<"open error"<<endl;
		return -1;
	}
	
	//���ж�ȡ����
	string line;
	while(getline(file,line)){
		if(func(line))
		     ++count;
		  line.clear();
	}

	file.close();
	return count;

}


int Parse_words(string Path){
	size_t count=0;
	ifstream file(Path.c_str());
	if(!file.is_open()){
		cout<<"open error"<<endl;
		return -1;
	}

	//���ж�ȡwords
	string line;
	while(getline(file,line)){
		if(func(line))
			count+=line.size();
		line.clear();
	}

	
	file.close();
	return count;

}


int main(){

    string path;
	int res1=0;
	int res2=0;
	
while(1){	
	cout<<"\n"<<endl;
	cout<<"��������Ҫ������text�ı�����·����  "<<endl;
	path.clear();
	getline(cin,path);
	if (Check(path))
	{
       
		res1=Parse_line(path);
		res2=Parse_words(path);   //һ������ռ����words
		
		cout<<"�����Ľ���ǣ� һ��"<<res1<<"������"<<" "<<res2<<"��words"<<endl;
		

		
	}

	else{

		cout<<"is not legal path ,Program  is going to exit...";
		
	}

}
	system("pause");
	return 0;
}
