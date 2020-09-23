#pragma once



namespace NativeExtensions
{
	template<typename T> class SafeArray final
	{
	private:
		T* ptr_;
		std::int32_t length_;
		bool dealloc_;

	public:
		SafeArray(std::int32_t length);
		SafeArray(const SafeArray& safeArray);
		SafeArray& operator=(const SafeArray& safeArray);
		T& operator[](std::int32_t index);
		~SafeArray();

	public:
		void Dispose();
		std::int32_t Length();
		void SetMemory()

	};
}
