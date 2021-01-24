# philosophers
*dining philosophers problem* (run `make` to compile)

#### tools used:
*philo_one* - threads, mutexes (<pthread.h>)

*philo_two* - threads, semaphors (<pthread.h>, <semaphore.h>)

*philo_three* - forks, semaphors (<unistd.h>, <semaphore.h>, <sys/wait.h>, <signal.h>)

---

#### arguments:
 1. `[number_of_philosophers]` - количество философов
 2. `[time_to_die]` - время в ms до смерти
 3. `[time_to_eat]` - время в ms на прием пищи
 4. `[time_to_sleep]` - время в ms на сон
 optional argument:
 5. `[number_of_times_each_philosopher_must_eat]` - количество приемов пищи
 ---
### examples:
 philo_one 5 800 200 200
 philo_one 5 800 200 200 7
 philo_two 4 310 200 100
 philo_three 4 410 200 200


