#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class date
{
private:
	int day;
	int month;
	int year;

public:
	date(int tday = 0, int tmon = 0, int tyear = 0) :day(tday), month(tmon), year(tyear)
	{
	}
	void setDate(int tday, int tmon, int tyear)
	{
		day = tday;
		month = tmon;
		year = tyear;
	}
	void getDate() // From user
	{
		cout << "Enter the day : ";
		cin >> day;
		cout << "Enter the month : ";
		cin >> month;
		cout << "Enter the year : ";
		cin >> year;
	}
	void displaydate()
	{
		cout << day << "/" << month << "/" << year << endl;
	}
};

class person // Person Info
{
protected:
	string first; // First Name
	string last; // Last Name
	string fname; // Father name
	string gender; // Gender
	string CNIC; // CNIC Number
	int id; // Unique ID assigned 
	string password; // Unique keywords to login

public:
	person(string tf = "None", string tl = "", string tfn = "None", string tg = "None", string tc = "None", int tid = 0, string tp = "None") :first(tf), last(tl), fname(tfn), gender(tg), CNIC(tc), id(tid)
	{
	}
	void setPerson(string tf, string tl, string tfn, string tg, string tc, int tid)
	{
		first = tf;
		last = tl;
		fname = tfn;
		gender = tg;
		CNIC = tc;
		id = tid;
	}
	void setID(int to)
	{
		id = to;
	}
	string getfirstName()
	{
		return first;
	}
	string getlastName()
	{
		return last;
	}
	int getID()
	{
		return id;
	}
	string getPassword()
	{
		return password;
	}
	void displayperson()
	{
		cout << "Full Name : " << first << " " << last << endl;
		cout << "Father Name : " << fname << endl;
		cout << "Gender : " << gender << endl;
		cout << "CNIC Number : " << CNIC << endl;
		cout << "Unique ID : " << id << endl;
	}
};

class lecture // For attendence
{
private:
	int students = 0; // No. of students enrolled in the course
	date ldate; // lecture date
	bool* attendence = NULL;

public:
	void setAttendence(int stu, date temp)
	{
		ldate = temp;
		students = stu;
		attendence = new bool[students];
	}
	void setTotalStu(int stu)
	{
		students = stu;
		attendence = new bool[students];
	}
	void setLecdate(date temp)
	{
		ldate = temp;
	}
	void markattendence(int index, bool state)
	{
		attendence[index] = state;
	}
	void displayA(int index)
	{
		if (attendence[index] == true)
		{
			cout << "Present" << endl;
		}
		else
		{
			cout << "Absent" << endl;
		}
	}
};

class assessment
{
private:
	string title; // Title of assignment
	double total; // Total marks
	double obtain; // Obtained marks
	double tw; // Total weightage
	double to; // Obtained weightage

public:
	assessment(string ttitle = "None", double ttotal = 0.0, double tobtain = 0.0, double ttw = 0.0, double tto = 0.0) :title(ttitle), total(ttotal), obtain(tobtain), tw(ttw), to(tto)
	{
	}
	void setAssessment(string ttitle, double ttotal, double tobtain, double ttw, double tto)
	{
		title = ttitle;
		total = ttotal;
		obtain = tobtain;
		tw = ttw;
		to = tto;
	}
	void setAssessment1(string ttitle, double ttotal, double ttw)
	{
		title = ttitle;
		total = ttotal;
		tw = ttw;
	}
	void setObtain(double tobtain)
	{
		obtain = tobtain;
		calculateWeightage();
	}
	void setObtainMarks(double tobtain)
	{
		obtain = tobtain;
	}
	void calculateWeightage()
	{
		to = (obtain / total) * tw;
	}
	double getObtainMarks()
	{
		return obtain;
	}
	double getObtainW() // Obtained weightage
	{
		return to;
	}
	double getTotalW()
	{
		return tw;
	}
	void displayassessment()
	{
		cout << "Title : " << title << endl;
		cout << "Total marks : " << total << endl;
		cout << "Total weightage : " << tw << endl;
	}
	void displayObtain()
	{
		cout << "Obtained marks : " << obtain << endl;
	}
};

class student : public person
{
private:
	date join; // Joining date
	int semester;
	int clist[6] = { 0,0,0,0,0,0 }; // Courses' list
	int ccount; // Course Counter

public:
	student(int ts = 0) :semester(ts), ccount(0)
	{
	}
	void setJoiningDate(date temp)
	{
		join = temp;
	}
	void setSemester(int ts)
	{
		semester = ts;
	}
	int getSemester()
	{
		return semester;
	}
	int getNoofCourses()
	{
		return ccount;
	}
	int* getclist()
	{
		return clist;
	}
	void enrollCourse(int coursecode)
	{
		if (ccount < 6)
		{
			clist[ccount] = coursecode;
			ccount++;
		}
		else
		{
			cout << "No more courses can be enrolled by this student. " << endl;
		}
	}
	void assignPassword(string tp)
	{
		password = tp;
	}
	void getStudata() // Getting data from user - 1st half
	{
		cin.ignore();
		cout << "Enter the details of the student below : " << endl << endl;
		cout << "Enter the first name : ";
		getline(cin, first);
		cout << "Enter the last name : ";
		getline(cin, last);
		cout << "Enter the father name : ";
		getline(cin, fname);
		cout << "Enter the gender of student : ";
		getline(cin, gender);
		cout << "Enter the CNIC/B-form number of student : ";
		getline(cin, CNIC);
	}
	void getStudata2() // Getting data from user - 2nd half
	{
		cout << "Enter the semester of the student : ";
		cin >> semester;
		cout << "Enter the joining date (DD-MM-YY) below : " << endl;
		join.getDate();
		cin.ignore();
		cout << "Assign a unique password to student : ";
		getline(cin, password);
	}
	void droparrangeS(int index)
	{
		int wait = 0;
		for (int i = index; i < ccount; i++)
		{
			wait = i + 1;
			clist[i] = clist[wait];
		}
		ccount--;
	}
	void displaystudent()
	{
		displayperson();
		cout << "Joining date : ";
		join.displaydate();
		cout << endl;
	}
};

class course
{
private:
	string title;
	int ccode; // Course code
	int semester;
	int credit; // Credit hours
	date starting; // Starting date
	int slist[50];
	int scount;
	char grade[50];
	double tp[50]; // Obtained weightage of students from the sum of weightages of assessments that are already done
	double op[50]; // Obtained percentage for grading
	assessment as[5][50]; // Assessments
	int acount; // Assessment Counter
	char attendence[10][50];
	lecture lectures[20]; // For attendence
	int lcount; // Lecture Counter
	int tid; // ID of teacher who is teaching this course
	double weightage; // Carry sum of weightages of assessments that are already done

public:
	course(string tt = "None", int tc = 0, int ts = 0, int tcredit = 0, int ttid = 0) :title(tt), ccode(tc), semester(ts), credit(tcredit), scount(0), acount(0), lcount(0), tid(ttid), weightage(0)
	{
		*slist = NULL;
		*tp = NULL;
		*grade = NULL;
		*op = NULL;
		**attendence = NULL;
	}
	void setCourse(string tt, int tc, int ts, int tcredit, date start)
	{
		title = tt;
		ccode = tc;
		semester = ts;
		credit = tcredit;
		starting = start;
	}
	void setCode(int to)
	{
		ccode = to;
	}
	void aTeacher(int ttid) // Assign Teacher
	{
		tid = ttid;
	}
	int getTID()
	{
		return tid;
	}
	int getCCode()
	{
		return ccode;
	}
	string getTitle()
	{
		return title;
	}
	void setSemester(int ts)
	{
		semester = ts;
	}
	int getSemester()
	{
		return semester;
	}
	int* getslist()
	{
		return slist;
	}
	int getNoofStudents()
	{
		return scount;
	}
	void getCourseData() // Getting input from user - 1st half
	{
		cin.ignore();
		cout << "Enter the details of the course below : " << endl << endl;
		cout << "Enter the title of course : ";
		getline(cin, title);
	}
	void getCourseData2() // Getting input from user - 1st half
	{
		cout << "Enter the semester no. which offers this course : ";
		cin >> semester;
		cout << "Enter the credit hours of the course :";
		cin >> credit;
		cout << "Enter the starting date (DD-MM-YY) below : " << endl;
		starting.getDate();
	}
	void addNewLecture()
	{
		if (lcount < 10)
		{
			lcount++;
			cout << "Enter attendence of lecture no. " << lcount << " below : " << endl;
			for (int i = 0; i < scount; i++)
			{
				cout << "Enter attendence for student whose id is " << slist[i] << " : ";
				cin >> attendence[lcount - 1][i];
			}
		}
		else
		{
			cout << "The lectures of this course are already completed. " << endl;
		}
	}
	void marklect(int leccount) // Mark attendence of the lecture
	{
		for (int i = 0; i < scount; i++)
		{
			bool temp;
			cout << "Enter the attendence (0 or 1) of student whose ID is " << slist[i] << " : ";
			cin >> temp;
			while (temp != true && temp != false)
			{
				cout << "Enter 0 or 1 to mark attendence : ";
				cin >> temp;
			}
			lectures[leccount].markattendence(i, temp);
		}
	}
	void addStudent(int studentid)
	{
		if (scount < 50)
		{
			slist[scount] = studentid;
			scount++;
		}
		else
		{
			cout << "No more students can enroll this course. " << endl;
		}
	}
	void addAssessment()
	{
		if (acount < 5)
		{
			acount++;
			createAssessment(acount - 1);
		}
		else
		{
			cout << "No more assessments can be taken. " << endl;
		}

	}
	void createAssessment(int ac)
	{
		string ttitle;
		double ttotal, ttw, tobtain;

		cin.ignore();
		cout << endl << "Enter the title of assessment : ";
		getline(cin, ttitle);
		cout << "Enter the total marks of assessment : ";
		cin >> ttotal;
		cout << "Enter the total weightage of the assessment : ";
		cin >> ttw;

		for (int i = 0; i < scount; i++)
		{
			as[ac][i].setAssessment1(ttitle, ttotal, ttw);

			cout << "Enter the obtained marks of the student against id " << slist[i] << " : ";
			cin >> tobtain;

			as[ac][i].setObtain(tobtain);
		}
	}
	void assessmentmarks(int stuid)
	{
		for (int i = 0; i < scount; i++)
		{
			if (stuid == slist[i])
			{
				int count = 1;
				cout << "Marks of the assessments of the student : " << endl;
				for (int j = 0; j < acount; j++)
				{
					cout << "Assessment no. " << count << endl;
					as[j][i].displayassessment();
					as[j][i].displayObtain();
					cout << endl;
					count++;
				}

				break;
			}
		}

	}
	void stuattendence(int stuid)
	{
		for (int i = 0; i < scount; i++)
		{
			if (stuid == slist[i])
			{
				int count = 1;
				cout << "Attendence of the student : " << endl;
				for (int j = 0; j < lcount; j++)
				{
					cout << "Lecture no. " << count << endl;
					cout << attendence[j][i] << endl;
					count++;
				}

				break;
			}
		}

	}
	void DMC(int stuid)
	{
		double store;
		cout << endl << "Course title : " << title << " - " << ccode << endl;
		for (int i = 0; i < scount; i++)
		{
			if (stuid == slist[i])
			{
				cout << "Grade : " << grade[i] << endl;
				if (grade[i] == 'A')
				{
					store = 4.0;
				}
				else if (grade[i] == 'B')
				{
					store = 3.3;
				}
				else if (grade[i] == 'C')
				{
					store = 2.6;
				}
				else if (grade[i] == 'D')
				{
					store = 2.0;
				}
				else
				{
					store = 1.0;
				}

				cout << "GPA : " << (store * credit) << " out of " << (4 * credit) << endl;
				break;
			}
		}
	}
	void assigngrades()
	{
		if (acount < 1)
		{
			cout << endl << "Grade can't be assigned because none of the assessments are done. " << endl;
		}
		else
		{
			for (int k = 0; k < acount; k++)
			{
				weightage += as[k][0].getTotalW();
			}
			for (int i = 0; i < scount; i++)
			{
				for (int k = 0; k < acount; k++)
				{
					tp[i] += as[k][i].getObtainW();
				}
				op[i] = (tp[i] / weightage) * 100;
			}
			for (int i = 0; i < scount; i++)
			{
				if (op[i] >= 90 || op[i] < 100)
				{
					grade[i] = 'A';
				}
				else if (op[i] >= 80 || op[i] < 90)
				{
					grade[i] = 'B';
				}
				else if (op[i] >= 60 || op[i] < 80)
				{
					grade[i] = 'C';
				}
				else if (op[i] >= 40 || op[i] < 60)
				{
					grade[i] = 'D';
				}
				else if (op[i] < 40)
				{
					grade[i] = 'F';
				}
			}
		}
	}
	void droparrangeC(int index)
	{
		int wait = 0;
		for (int i = index; i < scount; i++)
		{
			wait = i + 1;
			slist[i] = slist[wait];
		}
		scount--;
	}
	char getgrade(int index)
	{
		return grade[index];
	}
	void displayC()
	{
		cout << "Title : " << title << endl;
		cout << "Course code : " << ccode << endl;
		cout << "Semester : " << semester << endl;
		cout << "Credit Hours : " << credit << endl;
		cout << "Starting date : ";
		starting.displaydate();
	}
};

class faculty : public person
{
private:
	date join; // Joining date
	int clist[4];
	int ccount;

public:
	faculty() :ccount(0)
	{
		*clist = NULL;
	}
	void setJoiningDate(date temp)
	{
		join = temp;
	}
	void assignCourse(int coursecode)
	{
		if (ccount < 4)
		{
			ccount++;
			clist[ccount - 1] = coursecode;
		}
		else
		{
			cout << "A teacher can only teach 4 courses, no more can be added. " << endl;
		}
	}
	int getNoofCourses()
	{
		return ccount;
	}
	int* getclist()
	{
		return clist;
	}
	void assignPassword(string tp)
	{
		password = tp;
	}
	void getFacdata() // Getting data from user - 1st half
	{
		cin.ignore();
		cout << "Enter the details of the faculty member below : " << endl << endl;
		cout << "Enter the first name : ";
		getline(cin, first);
		cout << "Enter the last name : ";
		getline(cin, last);
		cout << "Enter the father name : ";
		getline(cin, fname);
		cout << "Enter the gender : ";
		getline(cin, gender);
		cout << "Enter the CNIC number : ";
		getline(cin, CNIC);
	}
	void getFacdata2() // Getting data from user - 2nd half
	{
		cout << "Enter the joining date (DD-MM-YY) below : " << endl;
		join.getDate();
		cin.ignore();
		cout << "Assign a unique password to faculty member : ";
		getline(cin, password);
	}
	void displayF() // Display Faculty
	{
		displayperson();
		cout << "Joining date : ";
		join.displaydate();
		cout << endl;
	}
};

class admin : public person
{
private:
	date join; // Joining date
	student* students = NULL;
	course* courses = NULL;
	faculty* teachers = NULL;
	int scount = 0; // Student Counter
	int ccount = 0; // Course Counter
	int tcount = 0; // Teacher Counter
	int slog = 0; // Student Log in ID
	int flog = 0; // Faculty Log in ID

public:
	void setJoiningDate(date temp)
	{
		join = temp;
	}
	void assignPassword(string tp)
	{
		password = tp;
	}
	void getAdmindata()
	{
		cout << "Enter the details of the admin below : " << endl << endl;
		cout << "Enter the first name : ";
		getline(cin, first);
		cout << "Enter the last name : ";
		getline(cin, last);
		cout << "Enter the father name : ";
		getline(cin, fname);
		cout << "Enter the gender : ";
		getline(cin, gender);
		cout << "Enter the CNIC number : ";
		getline(cin, CNIC);
		cout << "Enter the unique ID : ";
		cin >> id;
		cout << "Enter the joining date (DD-MM-YY) below : " << endl;
		join.getDate();
		cin.ignore();
		cout << "Set a password to login again : ";
		getline(cin, password);
	}
	void addFaculty()
	{
		if (tcount == 0)
		{
			tcount++;
			teachers = new faculty[tcount];
			teachers[tcount - 1].getFacdata();
			checkFID(tcount - 1);
			teachers[tcount - 1].getFacdata2();
		}
		else
		{
			faculty* store;
			int tempcount = tcount;
			store = new faculty[tempcount];

			for (int i = 0; i < tcount; i++)
			{
				store[i] = teachers[i];
			}

			delete[]teachers;

			tcount++;
			teachers = new faculty[tcount];

			for (int i = 0; i < tcount - 1; i++)
			{
				teachers[i] = store[i];
			}

			teachers[tcount - 1].getFacdata();
			checkFID(tcount - 1);
			teachers[tcount - 1].getFacdata2();

			delete[] store;
		}
		cout << "The faculty member has been added successfully. " << endl;
	}
	void addStudent()
	{
		if (scount == 0)
		{
			scount++;
			students = new student[scount];
			students[scount - 1].getStudata();
			checkSID(scount - 1);
			students[scount - 1].getStudata2();
		}
		else
		{
			student* temp;
			int tempcount = scount;
			temp = new student[tempcount];

			for (int i = 0; i < scount; i++)
			{
				temp[i] = students[i];
			}

			delete[]students;

			scount++;
			students = new student[scount];
			for (int i = 0; i < scount - 1; i++)
			{
				students[i] = temp[i];
			}
			students[scount - 1].getStudata();
			checkSID(scount - 1);
			students[scount - 1].getStudata2();

			delete[] temp;
		}
		cout << "The student has been added successfully. " << endl;
	}
	void addCourse()
	{
		if (ccount == 0)
		{
			int index;
			ccount++;
			courses = new course[ccount];
			courses[ccount - 1].getCourseData();
			checkCCode(ccount - 1);
			courses[ccount - 1].getCourseData2();
			index = ccount - 1;
			assignTeacher(index);
		}
		else
		{
			course* temp;
			int oindex;
			int tempcount = ccount;
			temp = new course[tempcount];

			for (int i = 0; i < ccount; i++)
			{
				temp[i] = courses[i];
			}

			delete[]courses;

			ccount++;
			courses = new course[ccount];

			for (int i = 0; i < ccount - 1; i++)
			{
				courses[i] = temp[i];
			}

			courses[ccount - 1].getCourseData();
			checkCCode(ccount - 1);
			courses[ccount - 1].getCourseData2();
			oindex = ccount - 1;
			assignTeacher(oindex);

			delete[] temp;
		}
		cout << "The course has been added successfully. " << endl;
	}
	void checkSID(int index)
	{
		int ssid;
		cout << "Enter the ID of student : ";
		cin >> ssid;
		while (ssid < 0)
		{
			cout << "Student ID can't be negative, enter again : ";
			cin >> ssid;
		}
	loop:
		for (int i = 0; i < scount; i++)
		{
			while (ssid == students[i].getID())
			{
				cout << endl << "Two students can't have same IDs. " << endl;
				cout << "Enter the ID of student : ";
				cin >> ssid;
				goto loop;
			}
		}
		students[index].setID(ssid);
	}
	void checkFID(int index)
	{
		int ffid;
		cout << "Enter the ID of faculty member : ";
		cin >> ffid;
		while (ffid < 0)
		{
			cout << "Faculty ID can't be negative, enter again : ";
			cin >> ffid;
		}
	loop:
		for (int i = 0; i < tcount; i++)
		{
			while (ffid == teachers[i].getID())
			{
				cout << endl << "Two faculty members can't have same IDs. " << endl;
				cout << "Enter the ID of faculty member : ";
				cin >> ffid;
				goto loop;
			}
		}
		teachers[index].setID(ffid);
	}
	void checkCCode(int index)
	{
		int ccd;
		cout << "Enter the course code : ";
		cin >> ccd;
		while (ccd < 0)
		{
			cout << "Course code can't be negative, enter again : ";
			cin >> ccd;
		}
	loop:
		for (int i = 0; i < ccount; i++)
		{
			while (ccd == courses[i].getCCode())
			{
				cout << endl << "Two courses can't have same course codes. " << endl;
				cout << "Enter the course code : ";
				cin >> ccd;
				goto loop;
			}
		}
		courses[index].setCode(ccd);
	}
	void displayAdmin()
	{
		displayperson();
		cout << "Joining date : ";
		join.displaydate();
		cout << endl;
	}
	void makeregistration()
	{
		int cc;
		cout << "Enter the course code of the course you've to register : ";
		cin >> cc;

		registerCourse(slog, cc);
	}
	void registerCourse(int stuid, int cc)
	{
		int trackc = 1;
		for (int i = 0; i < scount; i++)
		{
			if (stuid == students[i].getID())
			{
				for (int n = 0; n < ccount; n++)
				{
					if (cc == courses[n].getCCode())
					{
						if (students[i].getSemester() != courses[n].getSemester())
						{
							cout << "You can't register a course of another semester. " << endl << endl;
							break;
						}
						else
						{
							students[i].enrollCourse(cc);
							courses[n].addStudent(stuid);
							system("cls");
							cout << "The course is registered successfully. " << endl << endl;
							break;
						}
					}
					else if (trackc == ccount)
					{
						cout << "This Course code doesn't match to any course. " << endl;
						break;
					}
					trackc++;
				}
				break;
			}
		}
	}
	void dropCourse(int stuid, int cc)
	{
		int store;
		int* temp;
		int stored;
		int* temper;
		int indexs = 0;
		int indexc = 0;
		int track = 1;
		for (int i = 0; i < scount; i++)
		{
			if (stuid == students[i].getID())
			{
				indexs = i;
				break;
			}
		}
		for (int i = 0; i < ccount; i++)
		{
			if (cc == courses[i].getCCode())
			{
				indexc = i;
				break;
			}
		}
		temp = students[indexs].getclist();
		store = students[indexs].getNoofCourses();

		temper = courses[indexc].getslist();
		stored = courses[indexc].getNoofStudents();

		for (int i = 0; i < store; i++)
		{
			if (cc == temp[i])
			{
				for (int b = 0; b < stored; b++)
				{
					if (stuid == temper[b])
					{
						students[indexs].droparrangeS(i);
						courses[indexc].droparrangeC(b);
						break;
					}
				}
				break;
			}
			else if (track == store)
			{
				cout << "The student isn't enrolled in this course. " << endl;
				break;
			}
			track++;
		}
	}
	void dropacourse()
	{
		int cc;
		cout << "To drop a course, enter the course code of particular course : ";
		cin >> cc;
		while (cc < 0)
		{
			cout << "Course code can't be negative, re-enter : ";
			cin >> cc;
		}

		dropCourse(slog, cc);
	}
	void assignTeacher(int index)
	{
		int track = 1;
		int tc, cc;
		cout << "Assign a teacher to this course, enter ID of teacher : ";
		cin >> tc;

		cc = courses[index].getCCode();

		for (int i = 0; i < tcount; i++)
		{
			if (tc == teachers[i].getID())
			{
				courses[index].aTeacher(tc);
				teachers[i].assignCourse(cc);
				break;
			}
			else if (track == tcount)
			{
				cout << "This ID doesn't match to any teacher. " << endl;
				break;
			}
			track++;
		}
	}
	void viewenrolledcourses() // For Students
	{
		int index = 0;
		int* temp;
		int store;
		int count = 1;
		for (int i = 0; i < scount; i++)
		{
			if (slog == students[i].getID())
			{
				index = i;
				break;
			}
		}
		temp = students[index].getclist();
		store = students[index].getNoofCourses();
		cout << "List of the courses you're enrolled in are below : " << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					cout << count << ". " << courses[j].getTitle() << " - " << courses[j].getCCode() << endl;
					count++;
					break;
				}
			}
		}
	}
	void viewCTC() // View current teaching courses
	{
		int index = 0;
		int* temp;
		int store;
		int count = 1;
		for (int i = 0; i < tcount; i++)
		{
			if (flog == teachers[i].getID())
			{
				index = i;
				break;
			}
		}
		temp = teachers[index].getclist();
		store = teachers[index].getNoofCourses();
		cout << "List of the courses, you're teaching are below : " << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					cout << count << ". " << courses[j].getTitle() << " - " << courses[j].getCCode() << endl;
					count++;
					break;
				}
			}
		}
	}
	void viewSEC() // View students enrolled in each course
	{
		int index = 0;
		int* temp;
		int store;
		int count = 1;
		int counter = 1;
		int* temper;
		int stored;

		for (int i = 0; i < tcount; i++)
		{
			if (flog == teachers[i].getID())
			{
				index = i;
				break;
			}
		}
		temp = teachers[index].getclist();
		store = teachers[index].getNoofCourses();
		cout << "List of the courses, you're teaching are below : " << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					cout << count << ". " << courses[j].getTitle() << " - " << courses[j].getCCode() << endl << endl;

					temper = courses[j].getslist();
					stored = courses[j].getNoofStudents();

					cout << "List of students enrolled in this course is below : " << endl;
					for (int q = 0; q < stored; q++)
					{
						for (int w = 0; w < scount; w++)
						{
							if (temper[q] == students[w].getID())
							{
								cout << counter << ". " << students[w].getfirstName() << " " << students[w].getlastName() << " - " << students[w].getID() << endl;
								counter++;
								break;
							}
						}
					}

					count++;
					break;
				}
			}
		}
	}
	void loginF() // Log in for faculty
	{
		int temp;
		int track = 1;
		string store;

		cout << "Enter your unique id : ";
		cin >> temp;

		for (int i = 0; i < tcount; i++)
		{
			if (temp == teachers[i].getID())
			{
				int check = 0;
				cin.ignore();
				cout << "Enter your password : ";
				getline(cin, store);
				if (store == teachers[i].getPassword())
				{
					interfacefaculty();
				}
				else
				{
				loop:
					if (check <= 3)
					{
						if (store != teachers[i].getPassword())
						{
							cout << "Wrong password, re-enter your password : ";
							getline(cin, store);
							check++;
							goto loop;
						}
						else if (store == teachers[i].getPassword())
						{
							interfacefaculty();
						}
					}
					else
					{
						cout << "Invalid, you've entered wrong password many times. " << endl;
						back();
					}
				}
				break;
			}
			else if (track == tcount)
			{
				cout << "This ID doesn't match to any teacher. " << endl;
				back();
			}
			track++;
		}
		flog = temp;

		if (tcount == 0)
		{
			cout << "No faculty members are added yet. " << endl;
			back();
		}
	}
	void loginA() // Log in for admin
	{
		int temp;
		string store;

		cout << "Enter your unique id : ";
		cin >> temp;
		if (temp != id)
		{
			cout << "Your entered ID is invalid. " << endl;
			back();
		}
		else
		{
			int check = 0;
			cin.ignore();
			cout << "Enter your password : ";
			getline(cin, store);
			if (store == password)
			{
				interfaceadmin();
			}
			else
			{
			loop:
				if (check <= 3)
				{
					if (store != password)
					{
						cout << "Wrong password, re-enter your password : ";
						getline(cin, store);
						check++;
						goto loop;
					}
					else if (store == password)
					{
						interfaceadmin();
					}
				}
				else
				{
					cout << "Invalid, you've entered wrong password many times. " << endl;
					back();
				}
			}
		}
	}
	void loginS() // Log in for Students
	{
		int temp;
		int track = 1;
		string store;

		cout << "Enter your unique id : ";
		cin >> temp;

		for (int i = 0; i < scount; i++)
		{
			if (temp == students[i].getID())
			{
				int check = 0;
				cin.ignore();
				cout << "Enter your password : ";
				getline(cin, store);
				if (store == students[i].getPassword())
				{
					slog = temp;
					interfacestudents();
				}
				else
				{
				loop:
					if (check <= 3)
					{
						if (store != students[i].getPassword())
						{
							cout << "Wrong password, re-enter your password : ";
							getline(cin, store);
							check++;
							goto loop;
						}
						else if (store == students[i].getPassword())
						{
							slog = temp;
							interfacestudents();
						}
					}
					else
					{
						cout << "Invalid, you've entered wrong password many times. " << endl;
						back();
					}
				}
				break;
			}
			else if (track == scount)
			{
				cout << "ID not match to any student. " << endl;
				back();
			}
			else
			{
				track++;
			}
		}

		if (scount == 0)
		{
			cout << "No students are added yet. " << endl;
			back();
		}
	}
	void makenewlecture() // Make a new lecture and mark attendence
	{

		int index = 0;
		int indexc = 0;
		int* temp;
		int store, ccd, n;
		int count = 1;
		int trackc = 1;
		int trackx = 1;
		for (int i = 0; i < tcount; i++)
		{
			if (flog == teachers[i].getID())
			{
				index = i;
				break;
			}
		}
		temp = teachers[index].getclist();
		store = teachers[index].getNoofCourses();
		cout << "List of the courses, you're teaching are below : " << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					cout << count << ". " << courses[j].getTitle() << " - " << courses[j].getCCode() << endl;
					count++;
					break;
				}
			}
		}
		cout << endl << "Enter the course code of desired course to mark attendence : ";
		cin >> ccd;

		for (n = 0; n < ccount; n++)
		{
			if (ccd == courses[n].getCCode())
			{
				for (int i = 0; i < store; i++)
				{
					if (ccd == temp[i])
					{
						indexc = n;
						break;
					}
					else if (trackx == store)
					{
						cout << "This Course code doesn't match to any of your courses. " << endl;
						break;
					}
					trackx++;
				}
			}
			else if (trackc == ccount)
			{
				cout << "This Course code doesn't match to any course. " << endl;
				break;
			}
			trackc++;
		}

		courses[indexc].addNewLecture();
	}
	void createNewAssessment()
	{
		int index = 0;
		int indexc = 0;
		int* temp;
		int store, ccd, n;
		int count = 1;
		int trackc = 1;
		int trackx = 1;
		for (int i = 0; i < tcount; i++)
		{
			if (flog == teachers[i].getID())
			{
				index = i;
				break;
			}
		}
		temp = teachers[index].getclist();
		store = teachers[index].getNoofCourses();
		cout << "List of the courses, you're teaching are below : " << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					cout << count << ". " << courses[j].getTitle() << " - " << courses[j].getCCode() << endl;
					count++;
					break;
				}
			}
		}
		cout << endl << "Enter the course code of desired course to make new assessment : ";
		cin >> ccd;

		for (n = 0; n < ccount; n++)
		{
			if (ccd == courses[n].getCCode())
			{
				for (int i = 0; i < store; i++)
				{
					if (ccd == temp[i])
					{
						indexc = n;
						break;
					}
					else if (trackx == store)
					{
						cout << "This Course code doesn't match to any of your courses. " << endl;
						break;
					}
					trackx++;
				}
			}
			else if (trackc == ccount)
			{
				cout << "This Course code doesn't match to any course. " << endl;
				break;
			}
			trackc++;
		}

		courses[indexc].addAssessment();
	}
	void assigninggrades()
	{
		int index = 0;
		int indexc = 0;
		int* temp;
		int store, ccd, n;
		int count = 1;
		int trackc = 1;
		int trackx = 1;
		for (int i = 0; i < tcount; i++)
		{
			if (flog == teachers[i].getID())
			{
				index = i;
				break;
			}
		}
		temp = teachers[index].getclist();
		store = teachers[index].getNoofCourses();
		cout << "List of the courses, you're teaching are below : " << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					cout << count << ". " << courses[j].getTitle() << " - " << courses[j].getCCode() << endl;
					count++;
					break;
				}
			}
		}
		cout << endl << "To assign grades to the students who enrolled in a particular course " << endl;
		cout << "Enter the course code of desired course : ";
		cin >> ccd;

		for (n = 0; n < ccount; n++)
		{
			if (ccd == courses[n].getCCode())
			{
				for (int i = 0; i < store; i++)
				{
					if (ccd == temp[i])
					{
						indexc = n;
						break;
					}
					else if (trackx == store)
					{
						cout << "This Course code doesn't match to any of your courses. " << endl;
						break;
					}
					trackx++;
				}
			}
			else if (trackc == ccount)
			{
				cout << "This Course code doesn't match to any course. " << endl;
				break;
			}
			trackc++;
		}

		courses[indexc].assigngrades();
	}
	void showDMC()
	{
		int index = 0;
		int* temp;
		int store;
		int count = 1;
		for (int i = 0; i < scount; i++)
		{
			if (slog == students[i].getID())
			{
				index = i;
				break;
			}
		}
		temp = students[index].getclist();
		store = students[index].getNoofCourses();

		cout << "Student name : " << students[index].getfirstName() << " " << students[index].getlastName() << endl;
		cout << "Student ID : " << students[index].getID() << endl;
		cout << "Student semester " << students[index].getSemester() << endl << endl;
		cout << "         ---  DMC  ---         " << endl << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					courses[j].DMC(slog);
					break;
				}
			}
		}
	}
	void searchDMC() // For admin
	{
		int temps;
		int track = 1;
		int index = 0;
		int* temp;
		int store;
		cout << "To see the DMC of any student, enter student ID : ";
		cin >> temps;

		for (int i = 0; i < scount; i++)
		{
			if (temps == students[i].getID())
			{
				index = i;
				break;
			}
			else if (track == scount)
			{
				cout << "This ID doesn't match to any student. " << endl;
				break;
			}
			track++;
		}

		temp = students[index].getclist();
		store = students[index].getNoofCourses();

		cout << endl;
		cout << "Student name : " << students[index].getfirstName() << " " << students[index].getlastName() << endl;
		cout << "Student ID : " << students[index].getID() << endl;
		cout << "Student semester " << students[index].getSemester() << endl << endl;
		cout << "         ---  DMC  ---         " << endl << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					courses[j].DMC(temps);
					break;
				}
			}
		}

	}
	void showassess()
	{
		int talk;
		int index = 0;
		cout << "Enter course id to see assessments : ";
		cin >> talk;
		for (int i = 0; i < ccount; i++)
		{
			if (talk == courses[i].getCCode())
			{
				index = i;
				break;
			}
		}

		courses[index].assessmentmarks(slog);

	}
	void showattend()
	{
		int talk;
		int index = 0;
		cout << "Enter course id to see attendence : ";
		cin >> talk;
		for (int i = 0; i < ccount; i++)
		{
			if (talk == courses[i].getCCode())
			{
				index = i;
				break;
			}
		}

		courses[index].stuattendence(slog);

	}
	void viewgradeS() // View grade for each course
	{
		int index = 0;
		int rindex = 0;
		int* temp;
		int store;
		int* temper;
		int stored;
		int count = 1;
		for (int i = 0; i < scount; i++)
		{
			if (slog == students[i].getID())
			{
				index = i;
				break;
			}
		}

		temp = students[index].getclist();
		store = students[index].getNoofCourses();

		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					temper = courses[j].getslist();
					stored = courses[j].getNoofStudents();

					for (int q = 0; q < stored; q++)
					{
						if (temper[q] == slog)
						{
							rindex = q;
							break;
						}
					}

					cout << count << ". " << courses[j].getTitle() << " - Grade : " << courses[j].getgrade(rindex) << endl;
					count++;
				}
			}
		}
	}
	void back()
	{
		int next;
		cout << endl << "What to do next?" << endl;
		cout << "1. Back to main menu" << endl;
		cout << "2. Exit" << endl;
		cout << "Enter 1 or 2 : ";
		cin >> next;
		while (next < 1 || next > 2)
		{
			cout << "Wrong entry, enter again : ";
			cin >> next;
		}
		if (next == 1)
		{
			interface2();
		}
		else if (next == 2)
		{
			exit(0);
		}
	}
	void backadmin()
	{
		int next;
		cout << endl << "What to do next?" << endl;
		cout << "1. Go back to previous menu " << endl;
		cout << "2. Exit " << endl;
		cout << "Enter 1 or 2 : ";
		cin >> next;
		while (next < 1 || next > 2)
		{
			cout << "Wrong entry, enter again : ";
			cin >> next;
		}
		if (next == 1)
		{
			interfaceadmin();
		}
		else if (next == 2)
		{
			exit(0);
		}
	}
	void backstudent()
	{
		int next;
		cout << endl << "What to do next?" << endl;
		cout << "1. Go back to previous menu " << endl;
		cout << "2. Exit " << endl;
		cout << "Enter 1 or 2 : ";
		cin >> next;
		while (next < 1 || next > 2)
		{
			cout << "Wrong entry, enter again : ";
			cin >> next;
		}
		if (next == 1)
		{
			interfacestudents();
		}
		else if (next == 2)
		{
			exit(0);
		}
	}
	void backfaculty()
	{
		int next;
		cout << endl << "What to do next?" << endl;
		cout << "1. Go back to previous menu " << endl;
		cout << "2. Exit " << endl;
		cout << "Enter 1 or 2 : ";
		cin >> next;
		while (next < 1 || next > 2)
		{
			cout << "Wrong entry, enter again : ";
			cin >> next;
		}
		if (next == 1)
		{
			interfacefaculty();
		}
		else if (next == 2)
		{
			exit(0);
		}
	}
	void searchS() // Search student
	{
		int temps;
		int track = 1;
		cout << "Enter the student ID to search " << endl;
		cin >> temps;
		for (int i = 0; i < scount; i++)
		{
			if (temps == students[i].getID())
			{
				ISS(i);
			}
			else if (track == scount)
			{
				cout << "This ID doesn't match to any student. " << endl;
				break;
			}
			track++;
		}
	}
	void searchF() // Search faculty
	{
		int temps;
		int track = 1;
		cout << "Enter the faculty ID to search " << endl;
		cin >> temps;
		for (int i = 0; i < tcount; i++)
		{
			if (temps == teachers[i].getID())
			{
				ISF(i);
			}
			else if (track == tcount)
			{
				cout << "This ID doesn't match to any teacher. " << endl;
				break;
			}
			track++;
		}
	}
	void searchC() // Search course
	{
		int temps;
		int trackc = 1;
		cout << "Enter the course code to search " << endl;
		cin >> temps;
		for (int n = 0; n < ccount; n++)
		{
			if (temps == courses[n].getCCode())
			{
				ISC(n);
			}
			else if (trackc == ccount)
			{
				cout << "This Course code doesn't match to any course. " << endl;
				break;
			}
			trackc++;
		}
	}
	void readS(int index)
	{
		int store;
		int* temp;
		int count = 1;
		temp = students[index].getclist();
		store = students[index].getNoofCourses();
		students[index].displaystudent();
		cout << "List of the courses student enrolled in are below : " << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					cout << count << ". " << courses[j].getTitle() << " - " << courses[j].getCCode() << endl;
					count++;
					break;
				}
			}
		}
	}
	void readF(int index)
	{
		int store;
		int* temp;
		int count = 1;
		temp = teachers[index].getclist();
		store = teachers[index].getNoofCourses();
		teachers[index].displayF();
		cout << "List of the courses the teacher is teaching are below : " << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < ccount; j++)
			{
				if (temp[i] == courses[j].getCCode())
				{
					cout << count << ". " << courses[j].getTitle() << " - " << courses[j].getCCode() << endl;
					count++;
					break;
				}
			}
		}
	}
	void readC(int index)
	{
		int store;
		int storetid;
		int* temp;
		int count = 1;
		temp = courses[index].getslist();
		store = courses[index].getNoofStudents();
		storetid = courses[index].getTID();
		courses[index].displayC();
		cout << "Course teacher is : ";
		for (int p = 0; p < tcount; p++)
		{
			if (storetid == teachers[p].getID())
			{
				cout << teachers[p].getfirstName() << " " << teachers[p].getlastName() << " - " << teachers[p].getID() << endl;
				break;
			}
		}
		cout << "List of students enrolled in this course is below : " << endl;
		for (int i = 0; i < store; i++)
		{
			for (int j = 0; j < scount; j++)
			{
				if (temp[i] == students[j].getID())
				{
					cout << count << ". " << students[j].getfirstName() << " " << students[j].getlastName() << " - " << students[j].getID() << endl;
					count++;
					break;
				}
			}
		}
	}
	void deleteS(int index)
	{
		student* tempo;
		int wait = scount - 1;
		tempo = new student[wait];

		for (int n = index; n < wait; n++)
		{
			for (int i = 0; i < index; i++)
			{
				tempo[i] = students[i];
			}
			tempo[n] = students[n];
		}

		delete[] students;

		students = tempo;
		scount = wait;

		cout << "The student has been deleted successfully. " << endl << endl;
	}
	void deleteF(int index)
	{
		faculty* tempo;
		int wait = tcount - 1;
		tempo = new faculty[wait];

		for (int n = index; n < wait; n++)
		{
			for (int i = 0; i < index; i++)
			{
				tempo[i] = teachers[i];
			}
			tempo[n] = teachers[n];
		}

		delete[] teachers;

		teachers = tempo;
		tcount = wait;

		cout << "The faculty member has been deleted successfully. " << endl << endl;
	}
	void deleteC(int index)
	{
		course* tempo;
		int wait = ccount - 1;
		tempo = new course[wait];

		for (int n = index; n < wait; n++)
		{
			for (int i = 0; i < index; i++)
			{
				tempo[i] = courses[i];
			}
			tempo[n] = courses[n];
		}

		delete[] courses;

		courses = tempo;
		ccount = wait;

		cout << "The course has been deleted successfully. " << endl << endl;
	}
	void updateS(int index)
	{
		cout << "( Note: The ID can't be updated but you can update other details. )" << endl << endl;

		students[index].getStudata();
		students[index].getStudata2();

		cout << endl << "The student has been updated successfully. " << endl;
	}
	void updateF(int index)
	{
		cout << "( Note: The ID can't be updated but you can update other details. )" << endl << endl;

		teachers[index].getFacdata();
		teachers[index].getFacdata2();

		cout << endl << "The faculty member has been updated successfully. " << endl;
	}
	void updateC(int index)
	{
		cout << "( Note: The Course code can't be updated but you can update other details. )" << endl << endl;

		courses[index].getCourseData();
		courses[index].getCourseData2();

		cout << endl << "The course has been updated successfully. " << endl;
	}
	void interface1()
	{
		cout << "Firstly, set the admin !! " << endl << endl;
		getAdmindata();
		interface2();
	}
	void interface2()
	{
		int choice;
		system("cls");
		cout << "       ---  MAIN MENU  ---       " << endl << endl;
		cout << "1. Admin Log-in " << endl;
		cout << "2. Faculty/Teachers Log-in " << endl;
		cout << "3. Students Log-in " << endl;
		cout << "4. Exit " << endl << endl;
		cout << "Enter your choice from 1-4 : ";
		cin >> choice;
		while (choice < 1 || choice > 4)
		{
			{
				cout << "Wrong choice, Choose again : " << endl;
				cin >> choice;
			}
		}

		switch (choice)
		{
		case 1:
		{
			loginA();
			break;
		}
		case 2:
		{
			loginF();
			break;
		}
		case 3:
		{
			loginS();
			break;
		}
		case 4:
		{
			exit(0);
		}
		}
	}
	void interfaceadmin()
	{
		int option;
		system("cls");
		cout << "       ---  ADMIN MENU  ---       " << endl << endl;
		cout << "1. Add student " << endl;
		cout << "2. Add course " << endl;
		cout << "3. Add faculty " << endl;
		cout << "4. Search student to perform desired function " << endl;
		cout << "5. Search course to perform desired function " << endl;
		cout << "6. Search faculty to perform desired function" << endl;
		cout << "7. View DMC of any student " << endl;
		cout << "8. Log out " << endl << endl;
		cout << "Enter your choice from 1-8 : ";
		cin >> option;
		while (option < 1 || option > 8)
		{
			{
				cout << "Wrong choice, Choose again : " << endl;
				cin >> option;
			}
		}
		switch (option)
		{
		case 1:
		{
			system("cls");
			addStudent();
			backadmin();
			break;
		}
		case 2:
		{
			system("cls");
			addCourse();
			backadmin();
			break;
		}
		case 3:
		{
			system("cls");
			addFaculty();
			backadmin();
			break;
		}
		case 4:
		{
			system("cls");
			searchS();
			backadmin();
			break;
		}
		case 5:
		{
			system("cls");
			searchC();
			backadmin();
			break;
		}
		case 6:
		{
			system("cls");
			searchF();
			backadmin();
			break;
		}
		case 7:
		{
			system("cls");
			searchDMC();
			backadmin();
			break;
		}
		case 8:
		{
			interface2();
			break;
		}
		}
	}
	void interfacefaculty()
	{
		int option;
		system("cls");
		cout << "       ---  FACULTY MENU  ---       " << endl << endl;
		cout << "1. View the courses you're currently teaching " << endl;
		cout << "2. View students enrolled in each course " << endl;
		cout << "3. Add a new lecture and mark the attendence " << endl;
		cout << "4. Create new assessment and assign the marks " << endl;
		cout << "5. Assign grade for particular course based on the marks of students " << endl;
		cout << "6. Log out " << endl << endl;
		cout << "Enter your choice from 1-6 : ";
		cin >> option;
		while (option < 1 || option > 6)
		{
			{
				cout << "Wrong choice, Choose again : " << endl;
				cin >> option;
			}
		}
		switch (option)
		{
		case 1:
		{
			system("cls");
			viewCTC();
			backfaculty();
			break;
		}
		case 2:
		{
			system("cls");
			viewSEC();
			backfaculty();
			break;
		}
		case 3:
		{
			system("cls");
			makenewlecture();
			backfaculty();
			break;
		}
		case 4:
		{
			system("cls");
			createNewAssessment();
			backfaculty();
			break;
		}
		case 5:
		{
			system("cls");
			assigninggrades();
			backfaculty();
			break;
		}
		case 6:
		{
			flog = 0;
			interface2();
			break;
		}
		}
	}
	void interfacestudents()
	{
		int option;
		system("cls");
		cout << "       ---  STUDENT MENU  ---       " << endl << endl;
		cout << "1. Register a course " << endl;
		cout << "2. Drop a course " << endl;
		cout << "3. View the courses you're currently enrolled in " << endl;
		cout << "4. View the attendence for each particular course " << endl;
		cout << "5. View assessment marks for each assessment " << endl;
		cout << "6. View grade for each course " << endl;
		cout << "7. View your DMC " << endl;
		cout << "8. Log out " << endl << endl;
		cout << "Enter your choice from 1-8 : ";
		cin >> option;
		while (option < 1 || option > 8)
		{
			{
				cout << "Wrong choice, Choose again : " << endl;
				cin >> option;
			}
		}
		switch (option)
		{
		case 1:
		{
			system("cls");
			makeregistration();
			backstudent();
			break;
		}
		case 2:
		{
			system("cls");
			dropacourse();
			backstudent();
			break;
		}
		case 3:
		{
			system("cls");
			viewenrolledcourses();
			backstudent();
			break;
		}
		case 4:
		{
			system("cls");
			showattend();
			backstudent();
			break;
		}
		case 5:
		{
			system("cls");
			showassess();
			backstudent();
			break;
		}
		case 6:
		{
			system("cls");
			viewgradeS();
			backstudent();
			break;
		}
		case 7:
		{
			system("cls");
			showDMC();
			backstudent();
			break;
		}
		case 8:
		{
			slog = 0;
			interface2();
			break;
		}
		}
	}
	void ISS(int index) // Interface of student search
	{
		int option;
		system("cls");
		cout << "       ---  Which function to perform with searched student?  ---       " << endl << endl;
		cout << "1. Read " << endl;
		cout << "2. Update " << endl;
		cout << "3. Delete " << endl;
		cout << "4. Go back to previous menu " << endl;
		cout << "Enter your choice from 1-4 : ";
		cin >> option;
		while (option < 1 || option > 4)
		{
			{
				cout << "Wrong choice, Choose again : " << endl;
				cin >> option;
			}
		}
		switch (option)
		{
		case 1:
		{
			system("cls");
			readS(index);
			backadmin();
			break;
		}
		case 2:
		{
			system("cls");
			updateS(index);
			backadmin();
			break;
		}
		case 3:
		{
			system("cls");
			deleteS(index);
			backadmin();
			break;
		}
		case 4:
		{
			interfaceadmin();
			break;
		}
		}
	}
	void ISF(int index) // Interface of faculty search
	{
		int option;
		system("cls");
		cout << "       ---  Which function to perform with searched faculty member?  ---       " << endl << endl;
		cout << "1. Read " << endl;
		cout << "2. Update " << endl;
		cout << "3. Delete " << endl;
		cout << "4. Go back to previous menu " << endl;
		cout << "Enter your choice from 1-4 : ";
		cin >> option;
		while (option < 1 || option > 4)
		{
			{
				cout << "Wrong choice, Choose again : " << endl;
				cin >> option;
			}
		}
		switch (option)
		{
		case 1:
		{
			system("cls");
			readF(index);
			backadmin();
			break;
		}
		case 2:
		{
			system("cls");
			updateF(index);
			backadmin();
			break;
		}
		case 3:
		{
			system("cls");
			deleteF(index);
			backadmin();
			break;
		}
		case 4:
		{
			interfaceadmin();
			break;
		}
		}
	}
	void ISC(int index) // Interface of course search
	{
		int option;
		system("cls");
		cout << "       ---  Which function to perform with searched course?  ---       " << endl << endl;
		cout << "1. Read " << endl;
		cout << "2. Update " << endl;
		cout << "3. Delete " << endl;
		cout << "4. Go back to previous menu " << endl;
		cout << "Enter your choice from 1-4 : ";
		cin >> option;
		while (option < 1 || option > 4)
		{
			{
				cout << "Wrong choice, Choose again : " << endl;
				cin >> option;
			}
		}
		switch (option)
		{
		case 1:
		{
			system("cls");
			readC(index);
			backadmin();
			break;
		}
		case 2:
		{
			system("cls");
			updateC(index);
			backadmin();
			break;
		}
		case 3:
		{
			system("cls");
			deleteC(index);
			backadmin();
			break;
		}
		case 4:
		{
			interfaceadmin();
			break;
		}
		}
	}
};

int main()
{
	admin a;
	a.interface1();

	system("pause");
	return 0;
}