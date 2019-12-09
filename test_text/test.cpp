#include <iostream>
#include <fstream>
#include<string>
using namespace std;





bool func(string str){
	if(str.size()>1)
		return true;
	return false;


}


//检测.txt文件内容的有效行数和单词数
bool Check(string Path){
	//检测输入路径的后缀是否合法


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
	
	//按行读取内容
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

	//按行读取words
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
	cout<<"请输入需要解析的text文本完整路径：  "<<endl;
	path.clear();
	getline(cin,path);
	if (Check(path))
	{
       
		res1=Parse_line(path);
		res2=Parse_words(path);   //一个汉字占三个words
		
		cout<<"解析的结果是： 一共"<<res1<<"行内容"<<" "<<res2<<"个words"<<endl;
		

		
	}

	else{

		cout<<"is not legal path ,Program  is going to exit...";
		
	}

}
	system("pause");
	return 0;
}
