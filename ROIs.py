from epics import PV

class ROIs:
    def create(self, filename):
        self.fileName = filename
        with open(self.fileName, 'w') as file:
            file.write('energy' + '\t')
            header = '\t'.join([f'ROI{i+1}' for i in range(32)])
            file.write(header + '\n')
        
        self.PVs = []
        for i in range(32):
            self.PVs.append(PV(f"mcaTest:mca1.R{i}"))
        self.energy = PV("I11OH-PGM:getEnergy")

    def acquire(self):
        data = []
        data.append(self.energy.get(timeout=1, use_monitor=False))
        for pv in self.PVs:
            data.append(pv.get(timeout=1, use_monitor=False))

        with open(self.fileName, 'a+') as file:
            file.write('\t'.join(str(element) for element in data) + '\n')

