#pragma once

#include <iterator>
#include <mutex>


namespace vv
{

template <class TKey, class TValue>
const TValue& ConcurrentDictionary<TKey, TValue>::Get(const TKey& key) const
{
	std::shared_lock lock(_mutex);

	const auto search = _data.find(key);
	if (search == std::end(_data))
	{
		throw KeyNotFoundException(key);
	}
	return search->second;
}

template <class TKey, class TValue>
void ConcurrentDictionary<TKey, TValue>::Set(const TKey& key, const TValue& value)
{
	std::unique_lock lock(_mutex);

	const auto search = _data.find(key);
	if (search == std::end(_data))
	{
		_data.emplace(key, value);
	}
	else
	{
		search->second = value;
	}
}

template <class TKey, class TValue>
bool ConcurrentDictionary<TKey, TValue>::IsSet(const TKey& key) const
{
	std::shared_lock lock(_mutex);

	const auto search = _data.find(key);
	return search != std::end(_data);
}

template <class TKey, class TValue>
std::size_t ConcurrentDictionary<TKey, TValue>::Size() const noexcept
{
	return std::size(_data);
}

} // namespace vv
