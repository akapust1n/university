function Memory(num) {
	let self = this;

	let overflow = false;
	let arr = [];

	self.length = num;

	self.sayHi = function () {
		alert("Привет, я память на " + self.length + " элементов");
	};

	self.isOverflow = () => {
		return overflow;
	};

	self.push = (element) => {
		arr.push(element);

		if (arr.length > num) {
			overflow = true;
			arr.pop();
			throw new Error("переполнение");
		}
	};

	self.shift = () => {
		return arr.shift();
	};

	self.getLast = () => {
		return arr[arr.length - 1];
	};

	self.length = () => {
		return arr.length;
	};

	self.getFirst = () => {
		return arr[0];
	};

	self.print = () => {
		console.log("amount = " + index);
		console.log(arr);
	}

}