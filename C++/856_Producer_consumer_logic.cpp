

semaphore bin<1>;
counting_semaphore<N> full(0);
couting_semaphore<N> empty(N);

count = 0;
buffer = [];

while()
{
    empty.acquire();
    bin.acquire();

    bin.relase();
    full.release();
}

while()
{
    full.accure();
    bin.acquire();

    bin.relase();
    empty.release();
}