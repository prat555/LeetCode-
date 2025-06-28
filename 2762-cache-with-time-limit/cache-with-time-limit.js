class TimeLimitedCache {
    constructor() {
        this.cache = new Map();
    }

    set(key, value, duration) {
        const now = Date.now();
        const expiry = now + duration;
        let existed = false;
        if (this.cache.has(key)) {
            existed = true;
            clearTimeout(this.cache.get(key).timeoutId); // Clear previous timeout
        }
        const timeoutId = setTimeout(() => {
            this.cache.delete(key);
        }, duration);

        this.cache.set(key, {value, expiry, timeoutId});
        return existed;
    }

    get(key) {
        const now = Date.now();
        if (this.cache.has(key)) {
            const {value, expiry, timeoutId} = this.cache.get(key);
            if (expiry > now) {
                return value;
            } else {
                clearTimeout(timeoutId);
                this.cache.delete(key);
            }
        }
        return -1;
    }

    count() {
        const now = Date.now();
        let count = 0;
        for (const [key, {expiry}] of this.cache) {
            if (expiry > now) {
                count++;
            }
        }
        return count;
    }
}