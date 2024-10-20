#ifndef header_h
#define header_h
//function prototype
static string timer();

//message structure
struct msgstruct{
string message;
string timestamp;
//constructor
msgstruct(string a,string b) : message(a),timestamp(b){}
};

//functions
void sendmsg(vector<msgstruct> &msgvec){
    string msg;
    cout<<"\n";
    cout<<"Enter your message:";
    getline(cin,msg);
    msgvec.push_back(msgstruct(msg,timer()));
    cout<<"Message sent at "<<timer()<<"\n";
}
void viewmsg(vector<msgstruct> &msgvec){
    for(auto itr=msgvec.begin();itr != msgvec.end();){
    cout<<itr->message<<" "<<"["<<itr->timestamp<<"]";
    cout<<"\n";
    itr++;
    }
}  
void savemsg(vector<msgstruct> &msgvec){
    ofstream savefile;
    savefile.open("messages.txt");
    for(const auto &msg : msgvec){
        savefile<<msg.message <<" ["<< msg.timestamp<<"]"<< endl;

        msgvec.pop_back();
    }
    savefile.close();
}
void loadmsg(vector<msgstruct> &msgvec){
    string messages;
    ifstream loadfile;
    loadfile.open("messages.txt");
    while(getline(loadfile,messages)){
        msgvec.push_back(msgstruct(messages,timer()));
    }
}
void editmsg(vector<msgstruct> &msgvec){
    int index;
    string edited;
    for(int i=0;i<msgvec.size();i++){
        cout<<"["<<i<<"]"<<msgvec[i].message<<" "<<msgvec[i].timestamp<<"\n";
    }
    cout<<"enter message index:";
    cin>>index;
    cin.ignore();
    cout<<"Enter new message:";
    getline(cin,edited);
    msgvec[index].message = edited;
    cout<<"Edited successfully!";
    cout<<"\n";
}

static string timer(){
    const auto now = chrono::system_clock::now();
    time_t t= chrono::system_clock::to_time_t(now);
    string timestamp=std::ctime(&t);
    timestamp.pop_back();
    return timestamp;
}

void menu(){
    cout<<"\n";
    cout<<"-----MENU-----\n";
    cout<<"1.Send Messages.\n";
    cout<<"2.View Messages.\n";
    cout<<"3.Edit message.\n";
    cout<<"4.Save & Exit\n";
    cout<<"Enter your choice:";
}
#endif