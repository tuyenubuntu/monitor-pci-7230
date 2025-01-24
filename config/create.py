import os
from bs4 import BeautifulSoup

def create_sample_config():
    config = BeautifulSoup(features="xml")
    root = config.new_tag("CONFIGURATION")
    config.append(root)

    di = config.new_tag("DI")
    root.append(di)
    for i in range(16):
        port = config.new_tag("PORT", id=str(i), function="Reserve")
        di.append(port)

    do = config.new_tag("DO")
    root.append(do)
    for i in range(16):
        port = config.new_tag("PORT", id=str(i), function="Reserve")
        do.append(port)

    # Save to file
    os.makedirs('config', exist_ok=True)
    with open('config/configuration_io.xml', 'w') as f:
        f.write(config.prettify())

create_sample_config()
