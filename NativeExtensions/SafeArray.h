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
		T* GetPointer();

		void Copy(SafeArray& src, SafeArray& dest, std::int32_t count);
		void Copy(SafeArray& src, std::int32_t srcStart, SafeArray& dest, std::int32_t destStart, std::int32_t count);
		void ForEach(Method<void __cdecl(T)> method);
		T FindValue(Method<bool __cdecl(T)> method);
		const T& FindReference(Method<bool __cdecl(T)> method);
		std::int32_t FindIndex(Method<bool __cdecl(T)> method);
		bool Exists(Method<bool __cdecl(T)> method);

		void Resize(std::int32_t size);
	};
}
