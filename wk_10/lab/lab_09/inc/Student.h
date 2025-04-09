class Student
{
public:
    std::string First_Name;
    std::string Last_Name;
    int Mnumber;
    std::string Major;

    Student();
    ~Student();
};

    friend std::ostream& operator<<(Student st)
{
    
}
    friend std::ostream& operator<<( std::ostream& os, Student st)
    {
        return os << st.First_Name << "=" << st.count;
    }

