/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>

#include <fstream>

class DriveBase : public frc2::SubsystemBase {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  bool initialized = false;
  double driveConstant = -1;
  double speed = 1;

  WPI_TalonSRX * FrontL;
  WPI_TalonSRX * FrontR;
  WPI_TalonSRX * BackL;
  WPI_TalonSRX * BackR;
  frc::DifferentialDrive * _diffDrive;

  std::fstream recordfile {"/home/lvuser/wcrj/replay.txt"};

 public:
  DriveBase();
  void DriveBaseInit();
  void Periodic();
  void ArcadeDrive(double xAxis, double yAxis);
  void RampSwitch(bool rampOn);
  void reverseDrive(bool bButton);
  void slowDrive(bool yButton);
  void openFile();
  void closeFile();
};
