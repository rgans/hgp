#ifndef RRG_OBSERVER_H
#define RRG_OBSERVER_H

#pragma warning (push)
#pragma warning( disable : 4996 )
#include <boost/signals2.hpp>
#pragma warning (pop)

// Convenience wrapper for boost::signals2::signal.
template<typename Signature> class RRG_Observer {
public:
	RRG_Observer(const RRG_Observer&) = delete;
	RRG_Observer& operator=(const RRG_Observer&) = delete;
	RRG_Observer() = default;

private:
	template<typename Observers> friend class RRG_Observable;

	using Signal = boost::signals2::signal<Signature>;
	using SignalResult = typename Signal::result_type;

	Signal signal_;
};


// Generic observable mixin - users must derive from it.
template<typename Observers> class RRG_Observable {
private:
	using ObserverTable = typename Observers::ObserverTable;

public:
	// Registers an observer.
	template<size_t ObserverId, typename F> boost::signals2::connection Register(F&& f) {
		return std::get<ObserverId>(signals_).signal_.connect(std::forward<F>(f));
	}

protected:
	RRG_Observable() = default;

	// Notifies observers.
	template<size_t ObserverId, typename... Args> typename std::tuple_element<ObserverId, ObserverTable>::type::SignalResult Notify(Args&&... args) const {
		return std::get<ObserverId>(signals_).signal_(std::forward<Args>(args)...);
	}

private:
	ObserverTable signals_;
};

#endif