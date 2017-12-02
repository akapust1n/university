function Memory(num) {
	let self = this;

	let overflow = false;
	let arr = [];

	self.length = num;

	self.sayHi = function() {
		alert( "Привет, я память на " + self.length + " элементов");
	};

	self.isOverflow = function() {
		return overflow;
	};

	self.push = function(element) {
		arr.push(element);

		if (arr.length > num) {
			overflow = true;
			arr.pop();
			throw new Error("переполнение");
		}
	};

	self.shift = function() {
		return arr.shift();
	};

	self.getLast = function() {
		return arr[arr.length - 1];
	};

	self.length = function() {
		return arr.length;
	};

	self.getFirst = function() {
		return arr[0];
	};

	self.print = function() {
		console.log("amount = " + index);
		console.log(arr);
	}

}
