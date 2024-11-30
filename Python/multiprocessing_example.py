import multiprocessing
import concurrent.futures
import time


def do_something(process, second):
        print(f'Process {process} Sleeping {second} second...')
        time.sleep(second)
        print('Done sleeping...')

        return f'Process {process} Slept {second} second(s)'



def main():
    start_time = time.perf_counter()

    # # without using multiprocessing
    # # run synchronously
    # for i in range(10):
    #     do_something(1)

    # finish_time = time.perf_counter()
    # print(f'Finished in {finish_time - start_time} second(s)')


    # using multiprocessing
    # process_list = []
    # for i in range(10):
    #     p = multiprocessing.Process(target=do_something, args=[i, 1])
    #     p.start()
    #     process_list.append(p)
    
    # for i in range(10):
    #     # join() method will wait until the process is finished
    #     process_list[i].join()
    
    # finish_time = time.perf_counter()
    # print(f'Finished in {finish_time - start_time} second(s)')

    # using concurrent.futures module for submitting process more easily
    with concurrent.futures.ProcessPoolExecutor() as executor:
         secs = [1,2,3,4,5]
         results = [executor.submit(do_something, i, sec) for i, sec in enumerate(secs)]

         for i in concurrent.futures.as_completed(results):
             print(i.result())

    print(f'Finished in {time.perf_counter() - start_time} second(s)')


if __name__ == '__main__':
    main()
