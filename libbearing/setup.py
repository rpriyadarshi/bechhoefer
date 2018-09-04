from setuptools import setup

setup(name = 'libbearing',
      version = '1.0',
      description = 'Bearing Analyzer',
      url = 'http://www.virtualsamaj.com',
      author = 'VirtualSamaj',
      author_email = 'rohit@virtualsamaj.com',
      license = 'VirtualSamaj',
      packages = ['libbearing'],
      install_requires = [
            'smop',
      ],
      zip_safe = False)
