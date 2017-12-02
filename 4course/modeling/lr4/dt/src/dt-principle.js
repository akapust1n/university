include('src/source-of-information.js');
include('src/service-unit.js');
include('src/memory.js');

function findMinLengthQueue(dt, a, b, lambda, finishTime, releaseOrder) {
	let bmLength = 0;
	let flagRun = true;

	while (flagRun) {
		++bmLength;

		try {
			let si = new SourceOfInformation(a, b);
			let su = new ServiceUnitByPoisson(releaseOrder, lambda);

			let bm = new Memory(bmLength);
			console.log(bmLength)
			let nowTime = 0;
			let blocks = [si, su];

			while (nowTime < finishTime) {
				blocks.forEach(block => {
					block.run(nowTime, bm);
				})

				nowTime += dt;
			}
		} catch (err) {
			flagRun = !flagRun;
		} finally {
			flagRun = !flagRun;
		}
	}

	return bmLength;
}