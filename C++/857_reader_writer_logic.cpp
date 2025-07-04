
mutex db;
mutex mtx;

reader()
{
mtx.lock()
r++
if(r==1)
    db.lock
mtx.unlock()

mtx.lock()
r--;
if (r==0)
   db.unlock()
mtx.unlock() 


}



writer()
{
mtx.lock()
db.lock();

db.unlock();
mtx.unlock();
}