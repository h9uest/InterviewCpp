#ifndef _ConcurrentQueue_HPP_
#define _ConcurrentQueue_HPP_

#include <mutex>
#include <condition_variable>
#include <queue>

template<typename T, unsigned int Size>
class ConcurrentQueue
{
	protected:
		std::mutex mutex_;
		std::condition_variable queue_full_q_;
		std::condition_variable queue_empty_q_;
		//std::unique_lock<std::mutex> lock_;
		std::queue<T> queue_;

	public:
		void Push(T value);
		void Pop();
		T& Front();
};


template<typename T, unsigned int Size>
void ConcurrentQueue<T, Size>::Push(T value)
{
	std::unique_lock<std::mutex> lock(mutex_);
	while(queue_.size() == Size)
	{
		queue_full_q_.wait(lock);
	}

	queue_.push(value);
	lock.unlock();
	queue_empty_q_.notify_all();
}

template<typename T, unsigned int Size>
void ConcurrentQueue<T, Size>::Pop()
{
	std::unique_lock<std::mutex> lock(mutex_);
	while(queue_.size() == 0)
	{
		queue_empty_q_.wait(lock);
	}

	queue_.pop();
	lock.unlock();
	queue_full_q_.notify_all();
}

template<typename T, unsigned int Size>
T& ConcurrentQueue<T, Size>::Front()
{
	std::unique_lock<std::mutex> lock(mutex_);
	return queue_.front();
}

#endif
