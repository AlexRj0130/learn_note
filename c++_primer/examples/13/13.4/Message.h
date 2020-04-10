

swap(Message &, Message &);

class Message
{
friend class Folder;
friend swap(Message &, Message &);
public:
    explicit Message(const std::string &str = ""): contents(str) { }
    Message(const Message &);
    Message & operator=(Message);
    ~Message();
public:
    void save(Folder &);
    void remove(Folder &);
private:
    void add_to_Folders(const Message &);
    void remove_from_Folders();
private: 
    std::string contents;
    std::set<Folder *> folders;
};