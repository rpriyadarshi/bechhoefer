class Setup:
    def __init__(self):
        self.rd = 0  # roller diameter
        self.ca = 0  # contact angle in degrees
        self.ne = 0  # number of elements
        self.pd = 0  # pitch diameter
        self.side = 0  # inner or outer race fixed.  inner = 1, outer = 2
        self.thr = 0  # Threshold
        self.min = 0  # Minimum
        self.max = 0  # Maximum


class Bearing:
    def __init__(self):
        self.sr = 0  # Sample rate (samples/sec)
        self.gs = 0  # Vector of 'g' (accelerometer) data
        self.load = 0  # Load
        self.rate = 0  # Shaft rate


class Data:
    def __init__(self):
        self.bearing = Bearing()


class Peaks:
    def __init__(self):
        self.avg = 0
        self.min = 0
        self.max = 0
        self.val = []
        self.loc = []
        self.status = []


class Fault:
    def __init__(self):
        self.pks = Peaks()
        self.freqs = []
        self.spec = []
