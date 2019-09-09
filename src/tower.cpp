#include <iostream>
#include <cstdlib>

using namespace std;

//for 3 tower 3 obj.
class tower
{
  int *disk,cnt;
  int static totalDisk;
public:
  tower()
  {
    if(totalDisk==0)
    {
      cout<<"Enter no. of Disk : ";
      cin>>totalDisk;
    }
    disk = new int[totalDisk];
    for(int i=0;i<totalDisk;i++){
      disk[i]=cnt;
      cout<<disk[i]<<"\t";
    }

    //the largest disk is in totalDisk-cnt index

  }
  ~tower()
  {
    system("sl");
    cout<<"____________________";
    cout<<"|     You Win !!   |";
    cout<<"********************";
  }

  int setTower(int flg=0)  //flg=1 means source
  {
    if(flg!=1)
      return 127;
    cnt=totalDisk;
    for(int i=0;i<totalDisk;i++,cnt--)
      disk[i]=cnt;
    cnt=totalDisk;
    return 0;
  }

  int getCnt()
  { return cnt; }
  int static getTotalDisk()
  {return totalDisk;}
  int isEmpty()
  { return cnt==0; }
  int isFull()
  { return cnt==totalDisk; }

  int isDropValid(tower &r)
  {
    if(cnt==0)
      return 0;
    if(r.cnt==totalDisk)
      return 0;
    if(r.disk[r.cnt-1] > disk[cnt-1] || r.cnt==0)
      return 1; //Only way drop is valid
    return 127;
  }

  int dropTo(tower &r)
  {
    if(isDropValid(r) != 1)
    {
      cout<<"Drop is not valid";
      return 127;
    }
    r.disk[r.cnt++]=disk[--cnt];
    disk[cnt]=0;
    return 0; 
  }
  void display()
  {
    if(cnt == 0)
      cout<<"null";
    else{
      for(int i=0;i<cnt-1;i++)
	cout<<disk[i]<<"\t";
      cout<<disk[cnt-1]<<"*";
    }
  }
};
int tower::totalDisk=0;

int main()
{
  int n,i=0;
  int d,r;
  // n is total no. of disks
  do{
    if(i!=0)
      cout<<"You cannot enter no. less than 2 at min 3 towers !"<<endl;
    cout<<"Enter no. of towers : ";
    cin>>n;
    i++;
  }while(n<3);
  tower *a = new tower [n];
  cout<<"Tower 1 is set as source ";
  a[0].setTower(1);
  cout<<"Tower "<<n<<" is set as dest.\n\nLets Begin the game";
  for(i=0;i<n;i++){
    cout<<endl<<i+1<<"\t:\t";
    a[i].display();
    cout<<endl;
  }
  while(a[0].getTotalDisk() != a[n-1].getCnt()){
    cout<<"\nEnter tower to take disk from : ";
    cin>>d;
    cout<<"Enter reciver : ";
    cin>>r;
    if(a[d-1].dropTo(a[r-1]) == 0)
      for(i=0;i<n;i++){
	cout<<i+1<<"\t:\t";
	a[i].display();
	cout<<endl;
      }
  }
}
