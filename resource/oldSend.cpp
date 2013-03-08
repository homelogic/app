void Device::open_port(){
    if (serial.portName() != "COM3") {
        serial.close();
        serial.setPortName("COM3");
        if(serial.isOpen()){
            //do nothing
        }
        else{
            if (!serial.open(QIODevice::ReadWrite)) {
                processError(QObject::tr("Can't open %1, error code %2")
                             .arg(serial.portName()).arg(serial.error()));
                return;
            }
        }

        if (!serial.setBaudRate(QSerialPort::Baud19200)) {
            processError(QObject::tr("Can't set rate 19200 baud to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setDataBits(QSerialPort::Data8)) {
            processError(QObject::tr("Can't set 8 data bits to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setParity(QSerialPort::NoParity)) {
            processError(QObject::tr("Can't set no patity to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setStopBits(QSerialPort::OneStop)) {
            processError(QObject::tr("Can't set 1 stop bit to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setFlowControl(QSerialPort::NoFlowControl)) {
            processError(QObject::tr("Can't set no flow control to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }
    }
}

void Device::send(QByteArray &data, bool *status, int *devStatus){
    open_port();
    *status = true;

    int flagIndex;
    int success = 0;
    int timeout = 0;
    QString serialStatus;
    serialStatus = QObject::tr("Status: Running, connected to port %1.")
            .arg("COM3");
    qDebug() << serialStatus;

    qDebug() << "Size of Data to write: " << data.length();
    /* Do not quit trying to send message until you receive success
     * acknowledgement. Success ACK = 0x06
     * if the message is not sent successfully in 6 tries, quit */
    qDebug() << "Trying to write: " << data.toHex();
    while(success==0 && timeout <= 6){
        serial.write(data);
        serial.flush();
        serial.waitForReadyRead(600);
        response = serial.read(20);
        flagIndex = response.indexOf(0x21);
        if( response.endsWith(0x15)){ //Negative Acknowledgement
            qDebug() << "Error - NACK: " <<response.toHex();
            timeout++;
        }
        else if( response[8]==0x06 && flagIndex != -1 ){ //Positive ACK received
            qDebug() << "Successful Send: " << response.toHex();
            success=1;
            qDebug() << "Found 21 @ " << response.indexOf(0x21);
            if( (response.endsWith(0xFF))  ){
                *devStatus = 1;
                qDebug() << "Light is currently ON";
            }
            else if( (response.endsWith(QByteArray(0x00)))  ){
                *devStatus = 0;
                qDebug() << "Light is currently OFF";
            }
            else{
                //qDebug() << "Unkown status";
            }
        }else{
            qDebug() << "Error - Received: " <<response.toHex();
            timeout++;
        }
    }
    if(success==0){
        *status = false;
         //qDebug() << "Error - Received: " <<response.toHex();
    }
    response.clear();

}

void Device::send(QByteArray &data, bool *status)
{
    open_port();
    *status = true;
    int success = 0;
    int timeout = 0;
    QString serialStatus;
    serialStatus = QObject::tr("Status: Running, connected to port %1.")
            .arg("COM3");
    qDebug() << serialStatus;

    qDebug() << "Size of Data to write: " << data.length();

    /* Do not quit trying to send message until you receive success
     * acknowledgement. Success ACK = 0x06
     * if the message is not sent successfully in 6 tries, quit */
    while(success==0 && timeout <= 6){
        response.clear();
        serial.flush();
        qDebug() << "Trying to write: " << data.toHex();
        serial.write(data);
        serial.flush();
        serial.waitForReadyRead(400);
        response = serial.readAll();
        if( (response.endsWith(0x06)) || (response[9]==data[0] && response[10]==data[1])){ //Positive ACK received
            qDebug() << "Successful Send: " << response.toHex();
            success=1;
        }else{
            qDebug() << "Error - Received: " <<response.toHex();
            timeout++;
        }
    }

    if(success==0){
        *status = false;
    }
    response.clear();
}
