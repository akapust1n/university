include('src/source-of-information.js');
include('src/service-unit.js');
include('src/memory.js');

//[0]- время прихода
//[1] - время ухожа
//[2] - конечное время
function initBlock(fel, blocks, finishTime) {
	for (let i = 0; i < blocks.length; ++i) {
		fel[i] = blocks[i].getNextTime();
	}

	fel[blocks.length] = finishTime;
}

function getNumberMin(arr) {
	if (arr.length < 1) {
		throw new Error("пустой массив");
	}

	let iMin = 0;
	console.log("arr", arr.length)
	for (let i = 1; i < arr.length; ++i) {
		if (arr[iMin] > arr[i]) iMin = i;
	}

	return iMin;
}


function findMinLengthQueue(a, b, lambda, finishTime, releaseOrder) {
	let si = new SourceOfInformation(a, b);
	let su = new ServiceUnitByPoisson(releaseOrder, lambda);

	let bmLength = 0;
	let flagRun = true;

	while (flagRun) {
		++bmLength;

		try {
			runSimulation(si, su, bmLength, finishTime);
		} catch (err) {
			flagRun = !flagRun;
		} finally {
			flagRun = !flagRun;
		}
	}

	return bmLength;
}

function runSimulation(si, su, bmLength, finishTime) {

	let bm = new Memory(bmLength);

	let fel = [];

	let blocks = [si, su];

	initBlock(fel, blocks, finishTime);


	while (true) {
		let iMin = getNumberMin(fel);
		console.log(blocks.length)
		if (iMin == blocks.length) {
			break;
		}

		blocks[iMin].run(bm);
		fel[iMin] += blocks[iMin].getNextTime()
	}
}