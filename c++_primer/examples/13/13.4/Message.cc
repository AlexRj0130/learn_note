#include "Message.h"

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}


void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for(auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for(auto f : folders)
        f.remMsg(this);
}

Message::Message(const Message &m) :
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message & Message::operator=(Message rhs)
{
    swap(*this, rhs);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}